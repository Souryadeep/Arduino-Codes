void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0);

  int val = Serial.read() - 48;
  Serial.println(val);
}
