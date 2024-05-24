/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E5,NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
 
int noteDurations[] = {4, 6, 8, 9, 5};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 5; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 0;
    
    
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
   //delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
 for (int thisNote = 0; thisNote < 5; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2196 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
if(noteDurations[thisNote] == 4)
    {
        noteDuration = 2196 / 4 - 2196 / 16;
        delay(274.5);
    }
    else if(noteDurations[thisNote] == 6)
    {
         noteDuration = 2196 / 4 - 2196 / 16;
  
    }
    else if(noteDurations[thisNote] == 8)
    {
        noteDuration = 2196 / 16;
    }
   else if(noteDurations[thisNote] == 9)
    {
        noteDuration = 2196 / 4+ 2196/8;
    }
     else if(noteDurations[thisNote] == 5)
    {
        noteDuration= 2196 / 8;

    }


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

}
