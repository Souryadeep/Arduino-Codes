int ledPin1 = 6;
int switchPin1 = 2;
int ledPin2 = 9;
int switchPin2 = 8;
boolean lastButton1 = LOW;
boolean currentButton1 = LOW;
int ledLevel1 = 0;
boolean lastButton2 = LOW;
boolean currentButton2 = LOW;
int ledLevel2 = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode (switchPin1, INPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode (switchPin2, INPUT);
  pinMode (ledPin2, OUTPUT);
}

boolean debounce(boolean last, int x)
{
     boolean current = digitalRead(x);
     if (last != current)
     {
        delay(5);
        current = digitalRead(x);
      }  
      return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton1 = debounce(lastButton1, switchPin1);
  currentButton2 = debounce(lastButton2, switchPin2);

  if (lastButton1 == LOW && currentButton1 == HIGH)
  ledLevel1 = ledLevel1 + 51;

  if (lastButton2 == LOW && currentButton2 == HIGH)
  ledLevel2 = ledLevel2 + 51;

  lastButton1 = currentButton1;
  lastButton2 = currentButton2;

  if(ledLevel1 > 255)ledLevel1 = 0;
  if(ledLevel2 > 255)ledLevel2 = 0;
  
  analogWrite(ledPin1, ledLevel1);
  analogWrite(ledPin2, ledLevel2);
}
