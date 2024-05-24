
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4,0
};

int melody2[] = {
  NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_B3,
  0, NOTE_B3, 0, NOTE_E4,
  0, NOTE_E4, 0, NOTE_E4,
  NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_B4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_E4,
  0, NOTE_D4, 0, NOTE_FS4,
  0, NOTE_FS4, 0, NOTE_FS4,
  NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_E4,
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  250, 125, 125, 250, 250, 250, 250, 250, 250
};

int noteDurations2[] = {
  125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125
  };

byte flag = 0;

void setup() {
  // iterate over the notes of the melody:
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  for (int thisNote = 0; thisNote < 9 && flag == 0; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    noTone(8);
    if(digitalRead(4) == 0){
      flag = 1;
      break;
    }
  }


  for (int thisNote = 0; thisNote < 32 && flag == 1; thisNote++) {
    int noteDuration = noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    noTone(8);
    if(digitalRead(4) == 0){
      flag = 0;
      break;  
    }
  }

}
