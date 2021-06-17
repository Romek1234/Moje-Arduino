//local button pins
const byte BTN_MODE=5; //previous button
const byte BTN_NEXT=6; //previous button
const byte BTN_ENTER=7; //previous button
const byte BTN_PREV=8; //previous button

const byte MIDI_SYSEX=7; //code for SysEx command
const byte ID_HAUPTWERK=0x7D; //ID for Hauptwerk

int midiType=0; 
int data1=0;
int data2=0;

String hwline1="";
String hwline2="";
void setup() { 

  lcdinit();
  lcdclear();
  lcdbacklight(125);

  //setup local buttons
  pinMode(BTN_PREV, INPUT_PULLUP);
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_ENTER, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);

  updateDisplay();
} 

void lcdinit(){
  Serial1.begin(9600); 
  // Need to give LCD and backpack time to initialise 
  delay(800); 

  // Set display 16x2
  Serial1.write(5); 
  Serial1.write(2); 
  Serial1.write(16); 
  Serial1.write(0xFF);   
}

void lcdpos(byte row,byte column) {
  Serial1.write(2); 
  Serial1.write(row); 
  Serial1.write(column); 
  Serial1.write(0xFF); 

}  
void lcdclear(){
  // Clear Display 
  Serial1.write(4); 
  Serial1.write(0xFF); 
}

void lcdbacklight(byte brightness) {
  // Set backlight on
  Serial1.write(7); 
  Serial1.write(brightness); 
  Serial1.write(0xFF); 
}

void lcdstring(String what){
  Serial1.write(1); 
  Serial1.print(what); 
  Serial1.write(0xFF);   
}

void lcdchar(byte what){
  Serial1.write(10); 
  Serial1.write(what); 
  Serial1.write(0xFF);   
}

void loop() { 

  // Process incoming MIDI traffic for Sysex (no event handler)
  if (usbMIDI.read()) {
    midiType=usbMIDI.getType();
    data1=usbMIDI.getData1();
    data2=usbMIDI.getData2();
    //we are interested in SysEx messages
    if ((midiType == MIDI_SYSEX) && (data1 < 80)) {      
    //this is a SysEx message and will fit in our array   
    byte * sysexmessage=usbMIDI.getSysExArray();
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
  //process local buttons
  if (digitalRead(BTN_PREV) == 0) {
    usbMIDI.sendProgramChange(2,BTN_PREV);
  }

  if (digitalRead(BTN_MODE) == 0) {
    usbMIDI.sendProgramChange(2,BTN_MODE);
  }

  if (digitalRead(BTN_NEXT) == 0) {
    usbMIDI.sendProgramChange(2,BTN_NEXT);
  }
  if (digitalRead(BTN_ENTER) == 0) {
    usbMIDI.sendProgramChange(2,BTN_ENTER);
  }

}
void updateDisplay() {
  lcdpos(1,1); 
  lcdstring(hwline1);
  lcdpos(2,1);
  lcdstring(hwline2);
}
