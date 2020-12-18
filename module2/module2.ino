const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

const int redLedButton = 2;
const int yellowLedButton = 3;
const int greenLedButton = 4;

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
  toogleLed(redButtonState, redLedButton, redLedPin);
  toogleLed(yellowButtonState, yellowLedButton, yellowLedPin);
  toogleLed(greenButtonState, greenLedButton, greenLedPin);
}

void toogleLed(int buttonState, int button, int ledPin) {
  buttonState = digitalRead(button);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
