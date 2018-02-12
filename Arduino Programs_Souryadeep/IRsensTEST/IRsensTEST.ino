int distPin = 0;
int buzzer = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(distPin, INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dist = analogRead(distPin);
  if(dist<50)
  {
     //int x =  map(dist, 0,1023,0,255);
      tone(buzzer,1000);  
      delay(500);
      noTone(buzzer);
      //Serial.println(x);
      distance();
  }
  //Serial.println(dist);
  delay(200);
}

void distance()
{
int duration=pulseIn(distPin,HIGH);
Serial.println(duration);
delay(100);
  
}



