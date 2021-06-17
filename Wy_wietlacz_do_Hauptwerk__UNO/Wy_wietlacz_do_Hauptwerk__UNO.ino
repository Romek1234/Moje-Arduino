// LCD display for Hauptwerk
// Author: Romuald Milewski
// Based on Teensa's code from https://teensyhauptwerk.wordpress.com/

// Add Midi Library
#include <MIDI.h>   
//Sample using LiquidCrystal library
#include <LiquidCrystal.h> 
// select the pins used on the LCD panel
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
//local button pins
const byte BTN_MODE=9; //previous button
const byte BTN_NEXT=10; //previous button
const byte BTN_ENTER=11; //previous button
const byte BTN_PREV=12; //previous button

const byte MIDI_SYSEX=7; //code for SysEx command
const byte ID_HAUPTWERK=0x7D; //ID for Hauptwerk

int midiType=0; 
int data1=0;
int data2=0;

String hwline1="";
String hwline2="";
void setup() { 
    MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.turnThruOff(); // Turn off loop Midi IN to OUT
//  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
    // tells the Midi Library which function you want to call when a NOTE ON command
    // is received. In this case it's "MyHandleNoteOn".
//  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
    // to call "MyHandleNoteOff" when a NOTE OFF command is received.

//-----LCD initialization and initial text
  lcd.begin(16, 2); //Display type declaration (2x16)
  lcd.setCursor(0, 0); //Position the cursor on the first line
  lcd.print("Please wait"); //Display text on the first line
  lcd.setCursor(0, 1); //Position the cursor on the second line
  lcd.print("Loading"); //Display text on the second line
// ----End LCD initialization

  //setup local buttons
  pinMode(BTN_PREV, INPUT_PULLUP);
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_ENTER, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);


} 

void loop() { 

  // Process incoming MIDI traffic for Sysex (no event handler)
  if (MIDI.read()) {
    midiType=MIDI.getType();
    data1=MIDI.getData1();
    data2=MIDI.getData2();
    //we are interested in SysEx messages
    if ((midiType == MIDI_SYSEX) && (data1 < 80)) {      
    //this is a SysEx message and will fit in our array   
    byte * sysexmessage=MIDI.getSysExArray();
    hwline1="";
    hwline2="";
    if ((sysexmessage[1]==ID_HAUPTWERK) && (data1 > 24)) {
        //this is from Hauptwerk 

        for (int x=6; x<(22); x++){
          //step through sysex message 
          byte c=sysexmessage[x];
          hwline1 = hwline1 + char(c);
        }
        for (int x=22; x<(37); x++){
          //step through sysex message 
          byte c=sysexmessage[x];
          hwline2 = hwline2 + char(c);
        }
        updateDisplay();
      }

    }
  }
  //process local buttons ( - 4 for value 5,6,7,8 )
  if (digitalRead(BTN_PREV) == 0) {
    MIDI.sendProgramChange(2,BTN_PREV - 4);
  }

  if (digitalRead(BTN_MODE) == 0) {
    MIDI.sendProgramChange(2,BTN_MODE - 4);
  }

  if (digitalRead(BTN_NEXT) == 0) {
    MIDI.sendProgramChange(2,BTN_NEXT - 4);
  }
  if (digitalRead(BTN_ENTER) == 0) {
    MIDI.sendProgramChange(2,BTN_ENTER - 4);
  }

}
void updateDisplay() {
//---- dot. teensy
//  lcdpos(1,1); 
//  lcdstring(hwline1);
//  lcdpos(2,1);
//  lcdstring(hwline2);
//----- dot. teensy 
  lcd.clear();
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print(hwline1);
  lcd.setCursor(0,1);
  lcd.print(hwline2);
}
