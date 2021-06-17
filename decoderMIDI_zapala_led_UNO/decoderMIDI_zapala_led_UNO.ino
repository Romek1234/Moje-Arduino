#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13
 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {

pinMode (A0, OUTPUT); // Set Arduino board analog pins to output
digitalWrite (A0, LOW);
pinMode (A1, OUTPUT);
digitalWrite (A1, LOW);
pinMode (A2, OUTPUT);
digitalWrite (A2, LOW);
pinMode (A3, OUTPUT);
digitalWrite (A3, LOW);
pinMode (A4, OUTPUT);
digitalWrite (A4, LOW);
pinMode (A5, OUTPUT);

 

  for (int a=2; a<14; a++)
{
pinMode (a, OUTPUT); // Set Arduino board digital pins to output
digitalWrite (a, LOW); // Set Arduino board digitsl pins to KIGH
    
}
 

// self-test
  for (int a=2; a<14; a++)
{
digitalWrite (a, HIGH); // Set Arduino board digital pins to HIGH
delay(250); 
digitalWrite (a, LOW); // Set Arduino board digital pins to LOW
delay(50);  
}


 
 





  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.turnThruOff(); // Turn off loop Midi IN to OUT
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
    switch (pitch) {
  case 54+34:
    digitalWrite (A0, HIGH);
    break;
  case 55+34:
    digitalWrite (A1, HIGH);
    break;
    case 56+34:
    digitalWrite (A2,HIGH);
    break;
    case 57+34:
    digitalWrite (A3, HIGH);
    break;
    case 58+34:
    digitalWrite (A4, HIGH);
    break;
    case 59+34:
    digitalWrite (A5, HIGH);
    break;
   
    
    
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
   for (int a=2; a<14; a++)
{
   if (pitch == 58+a) {
digitalWrite (a, HIGH); // Set Arduino board pin 13 to output
 } 
}
  
  
    
   
}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
   switch (pitch) {
  case 54+34:
    digitalWrite (A0, LOW);
    break;
  case 55+34:
    digitalWrite (A1, LOW);
    break;
    case 56+34:
    digitalWrite (A2, LOW);
    break;
    case 57+34:
    digitalWrite (A3, LOW);
    break;
    case 58+34:
    digitalWrite (A4, LOW);
    break;
    case 59+34:
    digitalWrite (A5, LOW);
    break;
    
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}

   for (int a=2; a<14; a++)
{
   if (pitch == 58+a) {
digitalWrite (a, LOW); // Set Arduino board pin 13 to output
 } 
}
  
  
}
