// ze str. https://midiorgelprojekt.com/2019/04/25/midi-lcd-part-2/

// include the library code:
#include <LiquidCrystal.h>
#include <MIDI.h>

#define LED 13    // Arduino Board LED is on Pin 13

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
int displayNumber = 0;

void setup() {
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("MidiStops init..");
 
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output

  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  MIDI.setHandleSystemExclusive(MyHandleSystemExclusive); // set function for SysEx receive
  delay(1500); //just wait 1.5 seconds
  MIDI.turnThruOff(); // Turn off loop Midi IN to OUT
  
  lcd.clear(); //clear the LCD
  
  
}

void loop() {
  MIDI.read(); // Continuously check if Midi data has been received.
}

void MyHandleSystemExclusive(byte *data, unsigned int array_size)
{
  int column = 0;
  bool start = false;
  
  digitalWrite(LED,HIGH);  //Turn LED on - start working
  
 
  if (data[1] == 0x7d && data[2]==0x1b && data[3]==40){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.write("Loading organ:"); 
      lcd.setCursor(0,1);
      lcd.print(data[4]);
    
      return; 
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  if (data[1] == 0x7d){
  for (int i = 2; i < array_size; i++)
  {
    if (data[i] >= 32 && data[i] <= 126){
      lcd.write(data[i]);
      column = column + 1;
      if (column == 16)
      {
        lcd.setCursor(0,1);
      }
    }
  // sprawdznie ID komunikatu Sysex. jeśli 0x7d tzn. od Hauptwerka  
    if (data[i] == 0x7d){ 
    
        start = true;
    }
  }
  }
  digitalWrite(LED,LOW);  //Turn LED off - end working
}
