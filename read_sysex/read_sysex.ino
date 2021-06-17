#include <LiquidCrystal.h>
#include <MIDI.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
lcd.begin(16, 2);
MIDI.begin(MIDI_CHANNEL_OMNI);
}
void loop()
{
MIDI.read();
const byte *pMsg = MIDI.getSysExArray();
lcd.setCursor(0,0);
lcd.print(a);
lcd.print(" ");
}
