
/*

   This examples shows how to make a simple seven keys MIDI keyboard with volume control

   Created: 4/10/2015

   Author: Arturo Guadalupi <a.guadalupi@arduino.cc>

   

   http://www.arduino.cc/en/Tutorial/MidiDevice

*/

//#include "MIDI.h"

#define NUM_BUTTONS  8
#define NUM_KOLUMNS  8

//MIDI_CREATE_DEFAULT_INSTANCE();

const uint8_t key1 = 2;

const uint8_t key2 = 3;

const uint8_t key3 = 4;

const uint8_t key4 = 5;

const uint8_t key5 = 6;

const uint8_t key6 = 7;

const uint8_t key7 = 8;

const uint8_t key8 = 9;

// kolumny
const uint8_t kol1 = 10;
const uint8_t kol2 = 11;
const uint8_t kol3 = 12;
const uint8_t kol4 = A0;
const uint8_t kol5 = A1;
const uint8_t kol6 = A2;
const uint8_t kol7 = A3;
const uint8_t kol8 = A4;





const uint8_t buttons[NUM_BUTTONS] = {key1, key2, key3, key4, key5, key6, key7, key8};

const uint8_t kolumns[NUM_KOLUMNS] = {kol1, kol2, kol3, kol4, kol5, kol6, kol7, kol8};


uint8_t notesTime[NUM_BUTTONS];

 uint16_t pressedButtons = 0x00;

 uint16_t previousButtons = 0x00;



void setup() {
 //   MIDI.begin(MIDI_CHANNEL_OMNI); 
 //  MIDI.turnThruOff ();
  Serial.begin (31250);

  for (int i = 0; i < NUM_BUTTONS; i++){

    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(kolumns[i], INPUT_PULLUP);
    pinMode(kolumns[i], OUTPUT);
    digitalWrite(kolumns[i], HIGH); 
}
}
void loop(){

  readButtons();


  playNotes();
}





void readButtons(){
for (int j = 0; j < NUM_KOLUMNS; j++){
  digitalWrite(kolumns[j], LOW); 
  for (int i = 0; i < NUM_BUTTONS; i++){

    if (digitalRead(buttons[i]) == LOW){

      bitWrite(pressedButtons, i, 1);

     // delay(50);

    }

    else
  {
      bitWrite(pressedButtons, i, 0);

  }
}
digitalWrite(kolumns[j], HIGH); 
}

}

void playNotes()
{

  for (int i = 0; i < NUM_BUTTONS; i++){

    if (bitRead(pressedButtons, i) != bitRead(previousButtons, i)){

      if (bitRead(pressedButtons, i)){

        bitWrite(previousButtons, i , 1);

      // MIDI.sendNoteOn(i+47, 127, 1);
      Serial.write(0x90);
      Serial.write(i+47);
      Serial.write(0x45);

      }

      else

      {

        bitWrite(previousButtons, i , 0);

     // MIDI.sendNoteOff(i+47, 0, 1);
      Serial.write(0x90);
      Serial.write(i+47);
      Serial.write(0x00);

     

      }

    }

  }
}
