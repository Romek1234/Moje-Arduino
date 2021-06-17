
#include <MIDI.h>   // Add Midi Library
 
#define LED 13    // Arduino Board LED is on Pin 13
#define LED2 12
#define LED3 11

#define super_I 4
int count_super_I = 0;
int table_super_I[30];

#define II_to_I 5
int count_II_to_I = 0;
int table_II_to_I[30];

#define I_to_P 6
int count_I_to_P = 0;
int table_I_to_P[30];

#define II_to_P 7
int count_II_to_P = 0;
int table_II_to_P[30];

#define SUB_I 8
int count_SUB_I = 0;
int table_SUB_I[30];


 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (super_I, INPUT_PULLUP);
  pinMode (II_to_I, INPUT_PULLUP);
  pinMode (I_to_P, INPUT_PULLUP);
  pinMode (II_to_P, INPUT_PULLUP);
  pinMode (SUB_I, INPUT_PULLUP);
  
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
   if (pitch == 60) {
    digitalWrite(LED,HIGH);  //Turn LED on
   }
    if (channel == 1) {
      digitalWrite(LED2,HIGH);
    }
  if (digitalRead(super_I) == LOW && channel == 1) {
     digitalWrite(LED3,HIGH);
    pitch = pitch + 12;
    count_super_I = count_super_I + 1;
    table_super_I[count_super_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
  }
  if (digitalRead(II_to_I) == LOW && channel == 1) {
     // digitalWrite(LED3,HIGH);
    channel = channel + 1;
    count_II_to_I = count_II_to_I+ 1;
    table_II_to_I[count_II_to_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
  }
}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
 
    digitalWrite(LED,LOW);  //Turn LED off
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  
  if (digitalRead(super_I) == LOW && channel == 1) {
    pitch = pitch + 12;
    count_super_I = count_super_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
   } 
   else if ( count_super_I !=0 ) {
   
    for ( count_super_I; count_super_I >= 0; count_super_I--){
      pitch = table_super_I[count_super_I];
      MIDI.sendNoteOff (pitch, velocity, channel);
      }
    } 
    
  if (digitalRead(II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    count_II_to_I = count_II_to_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
   } 
   else if ( count_II_to_I !=0 ) {
   
    for ( count_II_to_I; count_II_to_I >= 0; count_II_to_I--){
      pitch = table_II_to_I[count_II_to_I];
      MIDI.sendNoteOff (pitch, velocity, channel);
      }
    } 
      
   
   
}
