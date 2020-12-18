#define NOTE_C1  261
#define NOTE_D1  294
#define NOTE_E1  329
#define NOTE_F1  349
#define NOTE_F1S  370
#define NOTE_G1  392
#define NOTE_A1  440
#define NOTE_B1  493

#define NOTE_VOID  0

const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

const int buzzer = 10;

const int melody[] = {
    NOTE_D1, NOTE_B1, NOTE_A1, NOTE_G1, NOTE_D1,
    NOTE_VOID, NOTE_VOID,
    NOTE_D1, NOTE_D1, NOTE_D1, //half beat
    NOTE_B1, NOTE_A1, NOTE_G1, 
    NOTE_E1, //double beat
    NOTE_VOID,
    NOTE_E1, NOTE_C1, NOTE_B1, NOTE_A1, NOTE_F1S,
    NOTE_VOID, NOTE_VOID,
    NOTE_D1, NOTE_D1, NOTE_C1, NOTE_A1, 
    NOTE_B1, //double beat
    NOTE_VOID,
    NOTE_D1, NOTE_B1, NOTE_A1, NOTE_G1, NOTE_D1,
    NOTE_VOID, NOTE_VOID,
    NOTE_D1, NOTE_D1, NOTE_D1, //half beat
    NOTE_B1, NOTE_A1, NOTE_G1, 
    NOTE_E1, //double beat
    NOTE_VOID,
    NOTE_E1, NOTE_C1, NOTE_B1, NOTE_A1, NOTE_D1, NOTE_D1, NOTE_D1, NOTE_D1, NOTE_E1, NOTE_D1, NOTE_C1, NOTE_A1, NOTE_G1,
    NOTE_VOID,
    NOTE_D1,
    NOTE_VOID,
    NOTE_B1, NOTE_B1, NOTE_B1,
    NOTE_VOID,
    NOTE_B1, NOTE_B1, NOTE_B1,
    NOTE_VOID,
    NOTE_B1, NOTE_D1, NOTE_G1, NOTE_A1, NOTE_B1,
    NOTE_VOID, NOTE_VOID,
    NOTE_C1, NOTE_C1, NOTE_C1,
    NOTE_VOID,
    NOTE_C1, NOTE_C1, //half beat
    NOTE_B1, NOTE_B1,
    NOTE_B1, NOTE_B1, NOTE_B1, //half beat
    NOTE_A1, NOTE_A1, NOTE_B1, 
    NOTE_A1, //bouble beat
    NOTE_D1, //double beat,
    NOTE_B1, NOTE_B1, NOTE_B1,
    NOTE_VOID,
    NOTE_B1, NOTE_B1, NOTE_B1,
    NOTE_VOID,
    NOTE_B1, NOTE_D1, NOTE_G1, NOTE_A1, 
    NOTE_B1, //double beat
    NOTE_VOID, //half beat
    NOTE_C1, NOTE_C1, NOTE_C1,
    NOTE_VOID, //half beat
    NOTE_C1, NOTE_C1, //half beat
    NOTE_B1, NOTE_B1,
    NOTE_B1, NOTE_B1, //half beat
    NOTE_D1, NOTE_D1, NOTE_C1, NOTE_A1,
    NOTE_G1 //double beat
};

int melodyIndex = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);

  if (melody[melodyIndex] == NOTE_C1 || melody[melodyIndex] == NOTE_F1 || melody[melodyIndex] == NOTE_B1) {
    digitalWrite(redLedPin, HIGH);    
  }

  if (melody[melodyIndex] == NOTE_D1 || melody[melodyIndex] == NOTE_G1) {
    digitalWrite(yellowLedPin, HIGH);    
  }

  if (melody[melodyIndex] == NOTE_E1 || melody[melodyIndex] == NOTE_A1) {
    digitalWrite(greenLedPin, HIGH);    
  }

  Serial.println(melodyIndex);
  
  tone(buzzer, melody[melodyIndex]);
  delay(550);

  noTone(buzzer);
  delay(50);

  if (melodyIndex < (sizeof(melody)/sizeof(melody[0])) - 1) {
    melodyIndex++;
  }
  else {
    noTone(buzzer);
    melodyIndex = 0;
    delay(10000);
  }
}
