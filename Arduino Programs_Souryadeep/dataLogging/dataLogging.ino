#include <SD.h>

int CS_pin = 10;
int IR_pin = 5;
int light_pin = 0;
long id = 1;

float refresh_rate = 0.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing Card");
  pinMode(CS_pin, OUTPUT);

  if (!(SD.begin()))
  {
    Serial.println("Card failed");
    return;
  }
  Serial.println("Card ready");
  delay(1000);

  File commandFile = SD.open("COMMANDS.txt");

  if (commandFile)
  {
    Serial.println("Reading the data file");

    float decade = pow(10, commandFile.available() - 1);
    while (commandFile.available())
    {
      float temp = commandFile.read() - '0';
      refresh_rate = temp * decade + refresh_rate;
      decade = decade / 10;
    }
    Serial.print("Refresh Rate = ");
    Serial.print(refresh_rate);
    Serial.println("ms");
    commandFile.close();
  }
  else
  {
    Serial.println("Could not read the file");
  }


  File logFile = SD.open("LOG.csv", FILE_WRITE);
  if (logFile)
  {
    logFile.println(", , , ,");
    String header = "ID, Light, IR";
    logFile.println("header");
    logFile.close();
    Serial.println(header);
  }
  else
  {
    Serial.println("Could not open log file");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_level = analogRead(light_pin);
  int IR_val = analogRead(IR_pin);

  String dataString = String(id) + String(light_level) + String(IR_val);

  File logFile = SD.open("LOG.csv", FILE_WRITE);
  if (logFile)
  {
    logFile.println(dataString);
    logFile.close();
    Serial.println(dataString);
  }
  else
  {
    Serial.println("Couldn't open log file");
  }

  id++;

  delay(refresh_rate);
}
