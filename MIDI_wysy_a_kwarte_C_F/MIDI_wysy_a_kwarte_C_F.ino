#include <MIDI.h>;

 

// Simple tutorial on how to send MIDI messages.

// Arduino will blink a led and play two notes.

 

MIDI_CREATE_DEFAULT_INSTANCE();

 

#define LED 13
 

void setup(){

pinMode(LED, OUTPUT);

MIDI.begin(MIDI_CHANNEL_OFF);

// Launch MIDI and tells program to disregard any MIDI incoming messages

}

void loop()

{

digitalWrite(LED,HIGH);

MIDI.sendNoteOn(60,127,1);

// Send a Note (pitch 60 (middle C), velo 127 on channel 1)

MIDI.sendNoteOn(65,127,1);

// Send a Note (pitch 65 (F), velo 127 on channel 1)

delay(200);

MIDI.sendNoteOff(60,0,1); // Stop the notes

MIDI.sendNoteOff(65,0,1);

digitalWrite(LED,LOW);

delay(100);

}
