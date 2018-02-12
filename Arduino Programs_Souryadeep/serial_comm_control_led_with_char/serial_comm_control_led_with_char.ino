int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0);
  
  int val = Serial.read() - 48;
  
  if(val == 1)
  {
      Serial.println("Led is on");
      digitalWrite(ledPin, HIGH);
  }
    else if(val == 0)
  {
      Serial.println("Led is off");
      digitalWrite(ledPin, LOW);
  }
      else
  {
        Serial.println("invalid"); 
  }
        
   Serial.flush();
}
