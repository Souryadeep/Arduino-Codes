#include <Servo.h>
int servoPin = 9 ;
int distPin = 0;
Servo souryasServo;
void setup() {
  // put your setup code here, to run once:
  
  souryasServo.attach(servoPin);
  Serial.begin(9600);
 
}

void loop() 
{
  // put your main code here, to run repeatedly:
    //int dist = analogRead(distPin);
    //int pos = map(dist, 0,1023,0,180);
    //Serial.println(dist);
    for(int i=0;i<=180;i=i+20)
    {
     souryasServo.write(i);
     Serial.println(i);
    }
     delay(1000);
     
     
      
  
}
