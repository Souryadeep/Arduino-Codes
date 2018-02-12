int motorPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<=255;i++)
  {
      analogWrite(motorPin,i);  
      delay(100);
  }
  delay(2000);
  for (int i = 255;i>=0;i--)
 {
    analogWrite(motorPin,i);
    delay(100); 
 }
 delay(2000);
  
}
