const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

const int redLedButton = 2;
const int yellowLedButton = 3;
const int greenLedButton = 4;

const int buzzer = 10;

int redButtonState = 0;
int yellowButtonState = 0;
int greenButtonState = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  pinMode(redLedButton, INPUT);
  pinMode(yellowLedButton, INPUT);
  pinMode(greenLedButton, INPUT);
}

void loop() {
  redButtonState = digitalRead(redLedButton);
  yellowButtonState = digitalRead(yellowLedButton);
  greenButtonState = digitalRead(greenLedButton);
  
  if (redButtonState && !yellowButtonState && !greenButtonState) {
    digitalWrite(redLedPin, HIGH);
    tone(buzzer, 100);
  }

  if (yellowButtonState && !redButtonState && !greenButtonState) {
    digitalWrite(yellowLedPin, HIGH);
    tone(buzzer, 500);
  }

   if (greenButtonState && !redButtonState && !yellowButtonState) {
    digitalWrite(greenLedPin, HIGH);
    tone(buzzer, 1000);
  }

  if (!greenButtonState && !redButtonState && !yellowButtonState) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    noTone(buzzer);
  }
}
