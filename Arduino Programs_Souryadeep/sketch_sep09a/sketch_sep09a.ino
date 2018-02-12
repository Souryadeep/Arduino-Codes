int irSenRead =0;
int buzzer=9;
int isObstacle = HIGH;
int delayRead =100;
void setup() {

  pinMode(irSenRead ,INPUT);
   pinMode(buzzer ,OUTPUT);
   Serial.begin(9600);

}

void loop() {

  isObstacle = digitalRead(irSenRead);
   Serial.println(digitalRead(irSenRead));

   // isObstacle ==low there is obstacle infront of sensor
  if (isObstacle == LOW) {
    digitalWrite(buzzer ,HIGH);
  }
  else
  {
    digitalWrite(buzzer ,LOW);
  }

  delay(delayRead);
}
