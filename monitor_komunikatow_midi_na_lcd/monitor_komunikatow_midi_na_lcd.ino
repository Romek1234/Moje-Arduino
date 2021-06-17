#include <MIDI.h>                        
#include <LiquidCrystal.h>             

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int delayTime = 400;                  

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);       
  lcd.begin(2,16);                     
}

void loop() {
  int type, channel, number;
  if (MIDI.read()) {                   
    byte type = MIDI.getType();        
    switch (type) {                   
      case NoteOn:                     
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Note On") + (",Note#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
        case NoteOff:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print(String("Note On") + (",Note#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case ControlChange:
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Ctl.Ch") + (", CC#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case ProgramChange:
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Prog.Ch") + (",Pgrm#") + number);
        lcd.setCursor(0,1);
        lcd.print(String(
        lcd.clear();
        break;
      case AfterTouchPoly:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("After Touch Poly:");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.
        lcd.clear();
        break;
       
        channel = MIDI
        lcd.
        lcd.print
        lcd.
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2
        lcd.clear();
        break;
      case 
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("Pitch Bend");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case SystemExclusive:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("Sysex");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
    }
  }
}
