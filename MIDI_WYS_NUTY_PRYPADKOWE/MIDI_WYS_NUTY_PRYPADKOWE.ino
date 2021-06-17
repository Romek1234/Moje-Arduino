#include <MIDI.h>;
// DX7 INT 27

MIDI_CREATE_DEFAULT_INSTANCE();

#define LED 13
#define progNumber 27 //definiujemy numer programu
int nuta;
int vel;
int przypadek;
int przypadek2;
int Dx7Preset[] = {1, 2, 3, 5, 7, 27};

void setup()
{
vel=31;
pinMode(LED, OUTPUT);
MIDI.begin(MIDI_CHANNEL_OFF); // Launch MIDI and tells program to disregard any MIDI incoming messages
//Serial.begin(19200);
MIDI.sendProgramChange(progNumber-1,1);

}

void loop()
{
for (int nuta = 122; nuta = 1; nuta --){

przypadek = random(1,60);

if ((nuta%(przypadek/5))==0)
//w przypadku gdy dzielenie nuty przez random/5 daje 0 zmień program
{
przypadek2 = random(0,5);
MIDI.sendProgramChange(Dx7Preset[przypadek2]-1,1);
//zmiana programu według przypadkowo wybranego preseta z tablicy
}
//vel=vel+(przypadek/5); // randomizacja velocity
digitalWrite(LED,HIGH);
MIDI.sendNoteOn(nuta,vel,1);
MIDI.sendNoteOn(nuta+przypadek,vel,1);
MIDI.sendNoteOn(nuta+5+przypadek,vel,1);
delay(100);
MIDI.sendNoteOff(nuta,vel,1);
MIDI.sendNoteOff(nuta+przypadek,vel,1);
MIDI.sendNoteOff(nuta+5+przypadek,vel,1);
digitalWrite(LED,LOW);
delay(20);}

}
