#include <SD.h>
#include <SPI.h>

int CS_pin = 10;
int refresh_rate = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing the Card");
  pinMode(CS_pin, OUTPUT);

  if(!(SD.begin(CS_pin)))
  {
      Serial.println("Card failed");
      return;  //entire program will terminate
  }
  Serial.println("Card Ready");

  File commandFile = SD.open("commands.txt");
  if (commandFile)
  {
      Serial.println("Reading command file");
      float decade = pow(10,(commandFile.available()-1));
      while(commandFile.available())
      {
          float temp = (commandFile.read() - '0');
          refresh_rate = temp*decade + refresh_rate;
          decade = decade/10;  
      }  
      Serial.print("Refresh Rate = ");
      Serial.print(refresh_rate);
      Serial.println("ms");
  }
  else
  {
      Serial.println("Could not open the command file"); 
      return; 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  String dataString = "Hello!";

  File dataFile = SD.open("log.txt", FILE_WRITE);

  if (dataFile)
  {
      dataFile.println(dataString);
      dataFile.close();
      Serial.println(dataString);  
  }
  else
  {
      Serial.println("Could not access the file");
    }

    delay(refresh_rate);
}
