#include <MIDI.h>   // Add Midi Library
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 



int delayTime =20;


void setup() {
 MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
 
lcd.begin(2,24); 

}

void loop(){
int type, channel, velocity, number;
word keyword;
MIDI.read(); // Continuously check if Midi data has been received.


if (1+1) { 
byte type = MIDI.getType(); 
channel = MIDI.getChannel();
number = MIDI.getData1();
if (type == 0xb0)
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("ControlChange") + (", CC #") + number);
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
} 

else if (type == 0x80) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("NoteOff ") + (", Note #") + number +("nn"));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(10);
}
else if (type == 0x90)
{NoteOn:
lcd.clear(); 
channel = MIDI.getChannel();
number = MIDI.getData1();
velocity = MIDI.getData2();
if (velocity > 0) {
lcd.setCursor(0,0);
lcd.print(String("Note_On ") + (", Note #") + number + ("nn"));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Velocity ") + MIDI.getData2());
delay(10);
} else {
lcd.setCursor(0,0);
lcd.print(String("NoteOff ") + (", Note #") + number + ("nn"));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Velocity ") + MIDI.getData2());
delay(10);
}
}

else if (type == 0xA0) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("AfterTouchPoly "));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
}

else if (type == 0xC0) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("ProgramChange") + (", Pgm #") + number);
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
}

else if (type == 0xD0) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("AfterTouchChannel "));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
}

else if (type == 0xE0) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("PitchBend "));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
}

else if (type == 0xF0) 
{
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print(String("SystemExclusive "));
lcd.setCursor(0,1);
lcd.print(String("Channel ") + channel + (", Value ") + MIDI.getData2());
delay(delayTime);
}


else{}

}
}
