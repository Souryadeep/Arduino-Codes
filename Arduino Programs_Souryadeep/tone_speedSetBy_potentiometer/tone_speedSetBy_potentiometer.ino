/*
  keyboard

 Plays a pitch that changes based on a changing analog input

 circuit:
 * 3 force-sensing resistors from +5V to analog in 0 through 5
 * 3 10K resistors from analog in 0 through 5 to ground
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 9 Apr 2012
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone3

 */

#include "pitches.h"

const float threshold = 2.5;    // minimum reading of the sensors that generates a note
const int potPin = 0;
// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};
int duration[] = {4,4,8,4};

void setup() {
  Serial.begin(9600);

}

void loop() {
  
    int sensorReading = analogRead(potPin);
    float valCompare = sensorReading * 5/1023;
    // if the sensor is pressed hard enough:
    if (valCompare > threshold) {
      // play the note corresponding to this sensor:
      for (int thisNote = 0; thisNote< 3; thisNote++)
      {
        float dur = 1000/valCompare;
        tone(8, notes[thisNote], dur);
        int pauseBetweenNotes = dur * 1.30;
        delay(pauseBetweenNotes);
       
      }
    }
    Serial.println(sensorReading);
  }

