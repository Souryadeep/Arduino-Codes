int switchPin = 8;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH)
  digitalWrite(led, HIGH);
  else
  digitalWrite(led,LOW);
}
