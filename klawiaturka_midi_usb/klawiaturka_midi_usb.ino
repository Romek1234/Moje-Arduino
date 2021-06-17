
/*

   This examples shows how to make a simple seven keys MIDI keyboard with volume control

   Created: 4/10/2015

   Author: Arturo Guadalupi <a.guadalupi@arduino.cc>

   

   http://www.arduino.cc/en/Tutorial/MidiDevice

*/

//#include "MIDI.h"

#define NUM_BUTTONS  19

//MIDI_CREATE_DEFAULT_INSTANCE();

const uint8_t key1 = 2;

const uint8_t key2 = 3;

const uint8_t key3 = 4;

const uint8_t key4 = 5;

const uint8_t key5 = 6;

const uint8_t key6 = 7;

const uint8_t key7 = 8;

const uint8_t key8 = 9;

const uint8_t key9 = 10;

const uint8_t key10 = 11;

const uint8_t key11 = 12;

const uint8_t key12 = A0;

const uint8_t key13 = A1;

const uint8_t key14 = A2;

const uint8_t key15 = A3;

const uint8_t key16 = A4;
const uint8_t key17 = A5;
const uint8_t key18 = A6;
const uint8_t key19 = A7;




const uint8_t buttons[NUM_BUTTONS] = {key1, key2, key3, key4, key5, key6, key7, key8, key9, key10, key11, key12, key13, key14, key15, key16, key17, key18, key19};



uint8_t notesTime[NUM_BUTTONS];

 uint16_t pressedButtons = 0x00;

 uint16_t previousButtons = 0x00;



void setup() {
 //   MIDI.begin(MIDI_CHANNEL_OMNI); 
 //  MIDI.turnThruOff ();
  Serial.begin (31250);

  for (int i = 0; i < NUM_BUTTONS; i++){

    pinMode(buttons[i], INPUT_PULLUP);
}
}
void loop(){

  readButtons();


  playNotes();
}





void readButtons(){

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
