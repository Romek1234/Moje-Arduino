#include <MIDI.h>   // Add Midi Library
void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI); 
  // put your setup code here, to run once:

}

void loop() {
  MIDI.read();
  // put your main code here, to run repeatedly:

}
