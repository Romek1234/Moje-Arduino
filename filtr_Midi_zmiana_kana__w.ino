#include <MIDI.h>   // Add Midi Library
 
#define LED 13    // Arduino Board LED is on Pin 13
#define LED2 12
#define LED3 11
#define LED4 10
#define set_channel 9

byte channel_value = 1;
byte channel_const = 1;


//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);

  pinMode (set_channel, INPUT_PULLUP); // set board pin ... to intput
 
  digitalWrite(LED, HIGH);
  
MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
MIDI.turnThruOff(); // To polecenie wyłacza automatyczny
  //przesył komunikatów z midiIn na midiOut
MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}

void loop() {
   MIDI.read(); // Continuously check if Midi data has been received.
   if (digitalRead(set_channel) == LOW) {
 channel_value_change();
}
}
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
 if (channel == channel_value) {
  MIDI.sendNoteOn (pitch, velocity, channel_const);
    // digitalWrite(LED,HIGH);  //Turn LED on for note c1
  }

}

  // MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
   if (channel == channel_value) {
   MIDI.sendNoteOff (pitch, velocity, channel_const);
    // digitalWrite(LED,LOW);  //Turn LED on for note c1
  }
}
// *************** channel_value_change*******************
void channel_value_change(){
   channel_value ++;
  if (channel_value == 5) { 
       channel_value = 1;
       }
          switch (channel_value) {
  case 1:
    digitalWrite(LED, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  
    break;
  case 2:
    digitalWrite(LED, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  
    break;
    case 3:
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  
    break;
    case 4:
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);

      default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
    MIDI.sendControlChange(123,0,channel_const);// All Notes Off  - CC (123, velosity 0, numer kanału)
    delay(750);
  
}
