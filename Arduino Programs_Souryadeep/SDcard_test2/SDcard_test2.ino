#include <SD.h>
#include <SPI.h>

int CS_pin = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  initializeSD();
  createFile("test.txt");
  writeToFile("This is sample text");
  closeFile();

  openFile("prefs.txt");
  Serial.println(readLine());
  Serial.println(readLine());
  closeFile();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void initializeSD()
{
    Serial.println("Initializing SD card");
    pinMode(CS_pin, OUTPUT);  
}
