int sensePin = 0;
int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(sensePin);
  val = constrain (val, 130,650);
  int ledLevel = map(val, 130, 650, 255, 0);
  
  analogWrite(ledPin, ledLevel);

  Serial.println(analogRead(sensePin));
}
