#include <MIDI.h>   // Add Midi Library
 
int midi_channel = 1; // jesli ma dziłac na kanale 1
 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

//Sterowanie zatrzaskiem 74HC595
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

unsigned long j = 0;
unsigned long k = 0;
int m = 0;
 
void setup() {

  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
  MIDI.setHandleControlChange(MyHandleControlChange);
  
 // inicjalizacja pinów od zatrzasku
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
/// Zerowanie zatrzasków
zatrzask_off();

}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}

//+++++++ Włączenie nuty+++++++
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
    if (channel == midi_channel) {
      if (pitch > 35 and pitch < 68) {
        bitSet(j, pitch - 36);
        zapiszdo595(j, k);
    }
         if (pitch > 67 and pitch < 100) {
        bitSet(k, pitch - 68);
        zapiszdo595(j, k);
    }
    }

}
  
  
    
   

 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
    if (channel == midi_channel) {
      if (pitch > 35 and pitch < 68) {
        bitClear(j, pitch - 36);
        zapiszdo595(j, k);
    }
         if (pitch > 67 and pitch < 100) {
        bitClear(k, pitch - 68);
        zapiszdo595(j, k);
    }

}
  
}  
void MyHandleControlChange(byte channel, byte number, byte value){
  if (number == 120) {
   zatrzask_off(); 
  }
  if (number == 123) {
   zatrzask_off(); 
  }
delay(300);
}

void zapiszdo595(unsigned long p,unsigned long q) {
 
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 24));
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 16));
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 8));
shiftOut(dataPin, clockPin, MSBFIRST, q);
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 24));
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 16));
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 8));
shiftOut(dataPin, clockPin, MSBFIRST, p);

digitalWrite(latchPin, HIGH);  
}
void zatrzask_off(){
       for (int i = 36; i < 101; i++) { 
     ///Serial.print(i, HEX);

     //Serial.print(" ");
  if (i > 35 and i < 69) {
        bitClear(j, i - 36);
        zapiszdo595(j, k);
    }
         if (i > 68 and i < 100) {
        bitClear(k, i - 69);
        zapiszdo595(j, k);
    }
  }
j=0;
k=0;
   zapiszdo595(j, k);
}
