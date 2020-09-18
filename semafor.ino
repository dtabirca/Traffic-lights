/*
 * traffic lights, with sound
 */

#define NOTE 973
#define PIN_CAR_RED 6
#define PIN_CAR_YELLOW 7
#define PIN_CAR_GREEN 4
#define PIN_PEDESTRIAN_RED 5
#define PIN_PEDESTRIAN_GREEN 3
#define PIN_SPEAKER 8
    
void setup() {

  pinMode(PIN_CAR_RED, OUTPUT);
  pinMode(PIN_CAR_YELLOW, OUTPUT);
  pinMode(PIN_CAR_GREEN, OUTPUT);
  pinMode(PIN_PEDESTRIAN_RED, OUTPUT);
  pinMode(PIN_PEDESTRIAN_GREEN, OUTPUT);
}

void loop() {

  digitalWrite(PIN_CAR_RED, HIGH);
  digitalWrite(PIN_PEDESTRIAN_RED, LOW);
  digitalWrite(PIN_PEDESTRIAN_GREEN, HIGH);
  delay(5000);
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/2;
    tone(PIN_SPEAKER, NOTE, noteDuration);
    digitalWrite(PIN_PEDESTRIAN_GREEN, HIGH);
    delay(500);
    digitalWrite(PIN_PEDESTRIAN_GREEN, LOW);
    delay(500);
    noTone(PIN_SPEAKER);
  }
  for (int thisNote = 0; thisNote < 12; thisNote++) {
    int noteDuration = 1000/4;
    tone(PIN_SPEAKER, NOTE, noteDuration);
    digitalWrite(PIN_PEDESTRIAN_GREEN, HIGH);
    delay(250);
    digitalWrite(PIN_PEDESTRIAN_GREEN, LOW);
    delay(250);
    noTone(PIN_SPEAKER);
  }  
  tone(PIN_SPEAKER, NOTE, 1000);

  digitalWrite(PIN_CAR_RED, LOW);
  digitalWrite(PIN_PEDESTRIAN_RED, HIGH);
  digitalWrite(PIN_CAR_GREEN, HIGH);
  delay(7000);
  digitalWrite(PIN_CAR_GREEN, LOW);
  digitalWrite(PIN_CAR_YELLOW, HIGH);
  delay(3000);
  digitalWrite(PIN_CAR_YELLOW, LOW);
}
