/*
  MIDI note player

  This sketch shows how to use the serial transmit pin (pin 1) to send MIDI note data.
  If this circuit is connected to a MIDI synth, it will play the notes
  F#-0 (0x1E) to F#-5 (0x5A) in sequence.

  The circuit:
  - digital in 1 connected to MIDI jack pin 5
  - MIDI jack pin 2 connected to ground
  - MIDI jack pin 4 connected to +5V through 220 ohm resistor
  - Attach a MIDI cable to the jack, then to a MIDI synth, and play music.

  created 13 Jun 2006
  modified 13 Aug 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Midi
*/
int n=0x00;
void setup() {
  // Set MIDI baud rate:
  Serial.begin(31250);
  randomSeed(analogRead(0));
  
}

void loop() {
 int n = random(0, 120);
 //n=80;
  ProgramChang(0xC0, n);// wysyła komunikat o zminamie programu - instrumentu w GM
 // n=n+1;
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
 // for (int note = 0x1E; note < 0x5A; note ++) {
    int note = random(0x1F, 0x5A);
    int note1 = random(0x1F, 0x5A);
    //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(0x90, note, 0x45);
    noteOn(0x91, note1, 0x45);
    
   // int a = random(40, 65);
    delay(40);
    //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(0x90, note, 0x00);
    delay(5);
 int m = random(0, 110);
 //n=80;
  ProgramChang(0xC1, m);// wysyła komunikat o zminamie programu - instrumentu w GM
 // n=n+1;
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
 // for (int note = 0x1E; note < 0x5A; note ++) {
//    int note1 = random(0x1F, 0x5A);
    //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
 //   noteOn(0x91, note1, 0x45);
    
   // int a = random(40, 65);
    delay(40);
    //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(0x91, note1, 0x00);
    delay(5);
  }
//}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
void ProgramChang(int cmd, int pitch) {
  Serial.write(cmd);
  Serial.write(pitch);

}
