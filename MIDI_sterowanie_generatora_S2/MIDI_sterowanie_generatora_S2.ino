

#include <MIDI.h>   // Add Midi Library
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
#define channelPlus  6
#define channelMinus  7
#define programPlus  8
#define programMinus  9
#define programPlus8  10
#define programMinus8  A0



int delayTime = 5; 
int progNr = 1;
int channNr = 1;
String instrument[16]  = {
"Piano ",
"Percusion ",
"Organ ",
"Guitar ",
"Bass ",
"Strings ",
"Ensemble ",
"Brass ",
"Reed ",
"Pipe ",
"Synth Lead ",
"Synth Pad ",
"Synth Effects ",
"Ethnic ",
"Percussive ",
"Effects ",
  };
/*  
char cString_instrument[]  = 
"1 Acoustic Grand Piano", 
"2 Bright Acoustic Piano", 
"3 Electric Grand Piano",
"4 Honky-tonk Piano",
"5 Electric Piano 1",
"6 Electric Piano 2",
"7 Harpsichord",
"8 Clavinet",
"9 Celesta",

"10 Glockenspiel",
"11 Music Box",
"12 Vibraphone",
"13 Marimba",
"14 Xylophone",
"15 Tubular Bells",
"16 Dulcimer",
"17 Drawbar Organ",
"18 Percussive Organ",
"19 Rock Organ",
"20 Church Organ",
"21 Reed Organ",
"22 Accordion",
"23 Harmonica",
"24 Tango Accordion",
"25 Acoustic Guitar (nylon)",
"26 Acoustic Guitar (steel)",
"27 Electric Guitar (jazz)",
"28 Electric Guitar (clean)",
"29 Electric Guitar (muted)",
"30 Overdriven Guitar",
};
/*
"31 Distortion Guitar",
"32 Guitar Harmonics",
"33 Acoustic Bass",
"34 Electric Bass (finger)",
"35 Electric Bass (pick)",
"36 Fretless Bass",
"37 Slap Bass 1",
"38 Slap Bass 2",
"39 Synth Bass 1",
"40 Synth Bass 2",
"41 Violin",
"42 Viola",
"43 Cello",
"44 Contrabass",
"45 Tremolo Strings",
"46 Pizzicato Strings",
"47 Orchestral Harp",
"48 Timpani",
"49 String Ensemble 1",
"50 String Ensemble 2",
"51 Synth Strings 1",
"52 Synth Strings 2",
"53 Choir Aahs",
"54 Voice Oohs",
"55 Synth Choir",
"56 Orchestra Hit",
"57 Trumpet"
"58 Trombone",
"59 Tuba",
"60 Muted Trumpet",
"61 French Horn",
"62 Brass Section",
"63 Synth Brass 1",
"64 Synth Brass 2",
"65 Soprano Sax",
"66 Alto Sax",
"67 Tenor Sax",
"68 Baritone Sax",
"69 Oboe",
"70 English Horn",
"71 Bassoon",
"72 Clarinet",
"73 Piccolo",
"74 Flute",
"75 Recorder",
"76 Pan Flute",
"77 Blown bottle",
"78 Shakuhachi",
"79 Whistle",
"80 Ocarina81 Lead 1 (square)",
"82 Lead 2 (sawtooth)",
"83 Lead 3 (calliope)",
"84 Lead 4 (chiff)",
"85 Lead 5 (charang)",
"86 Lead 6 (voice)",
"87 Lead 7 (fifths)",
"88 Lead 8 (bass + lead)",
"89 Pad 1 (new age)",
"90 Pad 2 (warm)",
"91 Pad 3 (polysynth)",
"92 Pad 4 (choir)",
"93 Pad 5 (bowed)",
"94 Pad 6 (metallic)",
"95 Pad 7 (halo)",
"96 Pad 8 (sweep)",
"97 FX 1 (rain)",
"98 FX 2 (soundtrack)",
"99 FX 3 (crystal)",
"100 FX 4 (atmosphere)",
"101 FX 5 (brightness)",
"102 FX 6 (goblins)",
"103 FX 7 (echoes)",
"104 FX 8 (sci-fi)105 Sitar",
"106 Banjo",
"107 Shamisen",
"108 Koto",
"109 Kalimba",
"110 Bagpipe",
"111 Fiddle",
"112 Shanai",
"113 Tinkle Bell",
"114 Agogo",
"115 Steel Drums",
"116 Woodblock",
"117 Taiko Drum",
"118 Melodic Tom",
"119 Synth Drum",
"120 Reverse Cymbal",
"121 Guitar Fret Noise",
"122 Breath Noise",
"123 Seashore",
"124 Bird Tweet",
"125 Telephone Ring",
"126 Helicopter",
"127 Applause",
"128 Gunshot"
};
*/
void setup() {
pinMode(channelPlus,INPUT_PULLUP);
pinMode(channelMinus,INPUT_PULLUP);
pinMode(programPlus,INPUT_PULLUP);
pinMode(programMinus,INPUT_PULLUP);
pinMode(programPlus8,INPUT_PULLUP);
pinMode(programMinus8,INPUT_PULLUP);

 MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.

 lcd.begin(16,2); 

delay(1000);

lcd.print(" Helo, GM SYNTH:  ");
delay(1000);

MIDI.sendProgramChange(progNr,channNr);
wypiszjakikomunikatmidi();

}

void loop(){
MIDI.read(); // Continuously check if Midi data has been received.
  
if (digitalRead(channelPlus) == LOW) { // sprawdza przycisk zwiekszenia nr kanału
  
  channNr++;
     if (channNr > 16) {
        channNr = 16;
        MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}
  
if (digitalRead(channelMinus) == LOW) {
  channNr--;
  if (channNr < 1) {
    channNr = 1;
  MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}

if (digitalRead(programPlus) == LOW) {
  progNr++;
  if (progNr > 128) {
    progNr = 128;
   MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}
   
if (digitalRead(programMinus) == LOW) {
  progNr--;
  if (progNr < 1) {
    progNr = 1;
   MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}
if (digitalRead(programPlus8) == LOW) {
  progNr=progNr + 8;
  if (progNr > 128) {
    progNr = 128;
   MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}
if (digitalRead(programMinus8) == LOW) {
  progNr=progNr - 8;
  if (progNr < 1) {
    progNr = 1;
   MIDI.sendProgramChange(progNr,channNr);
       wypiszjakikomunikatmidi();
        }
        else {
  MIDI.sendProgramChange(progNr,channNr);
  wypiszjakikomunikatmidi();
  }
}
   
}

void wypiszjakikomunikatmidi(){

lcd.clear(); 

lcd.setCursor(0,0);
lcd.print("MIDI Channel: ");
lcd.print(channNr);


lcd.setCursor(0,1);
lcd.print(instrument[(progNr-1)/8]);
lcd.print((progNr-1)%8+1);
delay(delayTime);
pauzowanie();
}

void pauzowanie(){
  int k=millis()/100;
  while(millis()/100 < k + 6){
   MIDI.read(); // Continuously check if Midi data has been received. 
  }
}
