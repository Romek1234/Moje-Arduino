//  MIDI_decoder
//  
//  Author:  Nick Gammon
//  Date:    8th April 2012.
//  Version: 1.0
//  Released into the public domain.

#include <SoftwareSerial.h>
#include <Streaming.h>

// Plug MIDI into pin D2 (MIDI in serial)

SoftwareSerial midi (2, 3);  // Rx, Tx

#define MESSAGE(which, desc) const char control_ ## which [] PROGMEM = desc; 
  
MESSAGE (0, "Bank Select (MSB)");
MESSAGE (1, "Modulation Wheel or Lever (MSB)");
MESSAGE (2, "Breath Controller (MSB)");
MESSAGE (3, "Undefined (MSB)");
MESSAGE (4, "Foot Controller (MSB)");
MESSAGE (5, "Portamento Time (MSB)");
MESSAGE (6, "Data Entry (MSB) (MSB)");
MESSAGE (7, "Channel Volume (formerly Main Volume) (MSB)");
MESSAGE (8, "Balance (MSB)");
MESSAGE (9, "Undefined:9 (MSB)");
MESSAGE (10, "Pan (MSB)");
MESSAGE (11, "Expression Controller (MSB)");
MESSAGE (12, "Effect Control 1 (MSB)");
MESSAGE (13, "Effect Control 2 (MSB)");
MESSAGE (14, "Undefined (MSB)");
MESSAGE (15, "Undefined (MSB)");
MESSAGE (16, "General Purpose Controller 1 (MSB)");
MESSAGE (17, "General Purpose Controller 2 (MSB)");
MESSAGE (18, "General Purpose Controller 3 (MSB)");
MESSAGE (19, "General Purpose Controller 4 (MSB)");
MESSAGE (20, "Undefined:20 (MSB)");
MESSAGE (21, "Undefined:21 (MSB)");
MESSAGE (22, "Undefined:22 (MSB)");
MESSAGE (23, "Undefined:23 (MSB)");
MESSAGE (24, "Undefined:24 (MSB)");
MESSAGE (25, "Undefined:25 (MSB)");
MESSAGE (26, "Undefined:26 (MSB)");
MESSAGE (27, "Undefined:27 (MSB)");
MESSAGE (28, "Undefined:28 (MSB)");
MESSAGE (29, "Undefined:29 (MSB)");
MESSAGE (30, "Undefined:30 (MSB)");
MESSAGE (31, "Undefined:31 (MSB)");
MESSAGE (32, "Bank Select (LSB)");
MESSAGE (33, "Modulation Wheel or Lever (LSB)");
MESSAGE (34, "Breath Controller (LSB)");
MESSAGE (35, "Undefined:35 (LSB)");
MESSAGE (36, "Foot Controller (LSB)");
MESSAGE (37, "Portamento Time (LSB)");
MESSAGE (38, "Data Entry (LSB)");
MESSAGE (39, "Channel Volume, formerly Main Volume (LSB)");
MESSAGE (40, "Balance (LSB)");
MESSAGE (41, "Undefined:41 (LSB)");
MESSAGE (42, "Pan (LSB)");
MESSAGE (43, "Expression Controller (LSB)");
MESSAGE (44, "Effect control 1 (LSB)");
MESSAGE (45, "Effect control 2 (LSB)");
MESSAGE (46, "Undefined:46 (LSB)");
MESSAGE (47, "Undefined:47 (LSB)");
MESSAGE (48, "General Purpose Controller 1 (LSB)");
MESSAGE (49, "General Purpose Controller 2 (LSB)");
MESSAGE (50, "General Purpose Controller 3 (LSB)");
MESSAGE (51, "General Purpose Controller 4 (LSB)");
MESSAGE (52, "Undefined:52 (LSB)");
MESSAGE (53, "Undefined:53 (LSB)");
MESSAGE (54, "Undefined:54 (LSB)");
MESSAGE (55, "Undefined:55 (LSB)");
MESSAGE (56, "Undefined:56 (LSB)");
MESSAGE (57, "Undefined:57 (LSB)");
MESSAGE (58, "Undefined:58 (LSB)");
MESSAGE (59, "Undefined:59 (LSB)");
MESSAGE (60, "Undefined:60 (LSB)");
MESSAGE (61, "Undefined:61 (LSB)");
MESSAGE (62, "Undefined:62 (LSB)");
MESSAGE (63, "Undefined:63 (LSB)");
MESSAGE (64, "Damper Pedal on/off (Sustain): < 64 is off, otherwise on");
MESSAGE (65, "Portamento On/Off: < 64 is off, otherwise on");
MESSAGE (66, "Sostenuto On/Off: < 64 is off, otherwise on");
MESSAGE (67, "Soft Pedal On/Off: < 64 is off, otherwise on");
MESSAGE (68, "Legato Footswitch: < 64 is Normal, otherwise Legato");
MESSAGE (69, "Hold 2: < 64 is off, otherwise on");
MESSAGE (70, "Sound Controller 1 (default: Sound Variation) (LSB)");
MESSAGE (71, "Sound Controller 2 (default: Timbre/Harmonic Intens.) (LSB)");
MESSAGE (72, "Sound Controller 3 (default: Release Time) (LSB)");
MESSAGE (73, "Sound Controller 4 (default: Attack Time) (LSB)");
MESSAGE (74, "Sound Controller 5 (default: Brightness) (LSB)");
MESSAGE (75, "Sound Controller 6 (default: Decay Time - see MMA RP-021) (LSB)");
MESSAGE (76, "Sound Controller 7 (default: Vibrato Rate - see MMA RP-021) (LSB)");
MESSAGE (77, "Sound Controller 8 (default: Vibrato Depth - see MMA RP-021) (LSB)");
MESSAGE (78, "Sound Controller 9 (default: Vibrato Delay - see MMA RP-021) (LSB)");
MESSAGE (79, "Sound Controller 10 (default undefined - see MMA RP-021) (LSB)");
MESSAGE (80, "General Purpose Controller 5 (LSB)");
MESSAGE (81, "General Purpose Controller 6 (LSB)");
MESSAGE (82, "General Purpose Controller 7 (LSB)");
MESSAGE (83, "General Purpose Controller 8 (LSB)");
MESSAGE (84, "Portamento Control (LSB)");
MESSAGE (85, "Undefined:85");
MESSAGE (86, "Undefined:86");
MESSAGE (87, "Undefined:87");
MESSAGE (88, "High Resolution Velocity Prefix (LSB)");
MESSAGE (89, "Undefined:89");
MESSAGE (90, "Undefined:90");
MESSAGE (91, "Effects 1 Depth");
MESSAGE (92, "Effects 2 Depth (formerly Tremolo Depth)");
MESSAGE (93, "Effects 3 Depth");
MESSAGE (94, "Effects 4 Depth (formerly Celeste [Detune] Depth)");
MESSAGE (95, "Effects 5 Depth (formerly Phaser Depth)");
MESSAGE (96, "Data Increment (Data Entry +1) (see MMA RP-018)");
MESSAGE (97, "Data Decrement (Data Entry -1) (see MMA RP-018)");
MESSAGE (98, "Non-Registered Parameter Number (NRPN) - (LSB)");
MESSAGE (99, "Non-Registered Parameter Number (NRPN) - (MSB)");
MESSAGE (100, "Registered Parameter Number (RPN) - (LSB)");
MESSAGE (101, "Registered Parameter Number (RPN) - (MSB)");
MESSAGE (102, "Undefined:102");
MESSAGE (103, "Undefined:103");
MESSAGE (104, "Undefined:104");
MESSAGE (105, "Undefined:105");
MESSAGE (106, "Undefined:106");
MESSAGE (107, "Undefined:107");
MESSAGE (108, "Undefined:108");
MESSAGE (109, "Undefined:109");
MESSAGE (110, "Undefined:110");
MESSAGE (111, "Undefined:111");
MESSAGE (112, "Undefined:112");
MESSAGE (113, "Undefined:113");
MESSAGE (114, "Undefined:114");
MESSAGE (115, "Undefined:115");
MESSAGE (116, "Undefined:116");
MESSAGE (117, "Undefined:117");
MESSAGE (118, "Undefined:118");
MESSAGE (119, "Undefined:119");
MESSAGE (120, "All Sound Off");
MESSAGE (121, "Reset All Controllers");
MESSAGE (122, "Local Control On/Off: 0 off, 127 on");
MESSAGE (123, "All Notes Off");
MESSAGE (124, "Omni Mode Off (+ all notes off)");
MESSAGE (125, "Omni Mode On (+ all notes off)");
MESSAGE (126, "Mono Mode On (+ poly off, + all notes off)");
MESSAGE (127, "Poly Mode On (+ mono off, +all notes off)");

//PROGMEM 
const char * messagesTable [128] =
{   
control_0, control_1, control_2, control_3, control_4, 
control_5, control_6, control_7, control_8, control_9, 
control_10, control_11, control_12, control_13, control_14, 
control_15, control_16, control_17, control_18, control_19, 
control_20, control_21, control_22, control_23, control_24, 
control_25, control_26, control_27, control_28, control_29, 
control_30, control_31, control_32, control_33, control_34, 
control_35, control_36, control_37, control_38, control_39, 
control_40, control_41, control_42, control_43, control_44, 
control_45, control_46, control_47, control_48, control_49, 
control_50, control_51, control_52, control_53, control_54, 
control_55, control_56, control_57, control_58, control_59, 
control_60, control_61, control_62, control_63, control_64, 
control_65, control_66, control_67, control_68, control_69, 
control_70, control_71, control_72, control_73, control_74, 
control_75, control_76, control_77, control_78, control_79, 
control_80, control_81, control_82, control_83, control_84, 
control_85, control_86, control_87, control_88, control_89, 
control_90, control_91, control_92, control_93, control_94, 
control_95, control_96, control_97, control_98, control_99, 
control_100, control_101, control_102, control_103, control_104, 
control_105, control_106, control_107, control_108, control_109, 
control_110, control_111, control_112, control_113, control_114, 
control_115, control_116, control_117, control_118, control_119, 
control_120, control_121, control_122, control_123, control_124, 
control_125, control_126, control_127
};  // end of messagesTable
  
int lookAhead;
unsigned long lastRead;

void setup() {
  //  Set MIDI baud rate:
  midi.begin(31250);
  Serial.begin(115200);
  Serial.println ();
  Serial.println (F("MIDI Decoder. Author: Nick Gammon."));
  lookAhead = -1;
} // end of setup

// get next byte from serial (blocks)
int getNext ()
  {
  while (midi.available () == 0)
    {}
  return midi.read ();
  }

const char * notes [] = { "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B " };

// interpret a note in terms of note name and octave
const char * getNote ()
  {
  byte note = getNext ();
  byte octave = note / 12;
  Serial << notes [note % 12] << F("(") << _DEC (octave - 1) << F(")");
  return " "; 
  }  // end of getNote
  
// dump a system exclusive message in hex
void showSystemExclusive ()
  {
  int count = 0;
  while (true)
    {
    while (midi.available () == 0)
      {}
    byte c = midi.read ();
    if (c >= 0x80)
      {
      Serial << endl;
      lookAhead = c;
      return;  
      }
    
    Serial << _HEX (c) << " ";
    if (++count > 32)
      {
      Serial << endl;
      count = 0;  
      }
    } // end of reading until all system exclusive done
  }  // end of showSystemExclusive
  
/* Print a string from Program Memory directly to save RAM */
void printProgStr (const char * str)
{
  char c;
  if(!str) return;
  while((c = pgm_read_byte(str++)))
    Serial.print(c);
} // end of printProgStr

// show a control message by looking up in the table
void showControlMessage ()
  {
   byte message =  getNext () & 0x7F;
   byte param = getNext ();
   // get address from progmem, display each byte
   printProgStr ((const char *) pgm_read_word(&(messagesTable[message])));
   // show parameter in hex
   Serial << ": 0x" << _HEX (param) << endl;
  }  // end of showControlMessage
  
void loop() 
{
  byte c;
  
  // system exclusive reads ahead one byte, to get a byte with the high-order bit set
  if (lookAhead == -1)
    {
    if (!midi.available ())
      return;
   
    c = midi.read ();
    } // end of if no look ahead byte
  else
    c = lookAhead;
    
  // done with look ahead
  lookAhead = -1;
 
  // channel is in low order bits
  int channel = (c & 0x0F) + 1;
  
  // ignore stuff that keep churning out
  if (c == 0xF8 ||  // timing clock
      c == 0xFE)    // active sensing
    return;  // too much information 

  // show time since last message in microseconds
  char buf [15];
  ltoa (micros () - lastRead, buf, 10);
  byte spaces = 10 - strlen (buf);
  for (byte i = 0; i < spaces; i++)
    Serial << " ";
  
  // show elapsed time
  Serial << buf << ": ";  
  lastRead = micros ();
    
  // messages start with high-order bit set
  if (c & 0x80)
    {
    switch ((c >> 4) & 0x07)
      {
      case 0: 
        Serial << F("Note off channel = ") << channel << F(", note = ") << getNote () << F(", velocity = ") << getNext () << endl;
        break;
        
      case 1: 
        Serial << F("Note  on channel = ") << channel << F(", note = ") << getNote () << F(", velocity = ") << getNext () << endl;
        break;
        
      case 2: 
        Serial << F("Polyphonic pressure channel = ") << channel << F(", note = ") << getNote () << F(", pressure = ") << getNext () << endl;
        break;
        
      case 3: 
        Serial << F("Control change channel = ") << channel << ", ";
        showControlMessage ();
        break;
        
      case 4: 
        Serial << F("Program change channel = ") << channel << F(", program = ") << getNext () << endl;
        break;
        
      case 5: 
        Serial << F("After-touch pressure channel = ") << channel << F(", value = ") << getNext () << endl;
        break;
        
      case 6: 
        Serial << F("Pitch wheel change channel = ") << channel << F(", value = ") << (getNext () | getNext () << 7) << endl;
        break;
        
      case 7:  // system message
        {
        Serial << "System: ";
        switch (c & 0x0F)
          {
          case 0:
            Serial << F("Exclusive (in hex)") << F(", vendor ID = ") << getNext () << endl;
            showSystemExclusive ();
            break;
            
          case 1:
            Serial << F("Time code: value/type = ") << getNext () << endl;
            break;
          
          case 2: 
            Serial << F("Song position pointer, value = ") << (getNext () | getNext () << 7) << endl;
            break;
          
          case 3:
            Serial << F("Song select, song = ") << getNext () << endl;
            break;

          case 4:
            Serial << F("Reserved (4)") << endl;
            break;

          case 5:
            Serial << F("Reserved (5)") << endl;
            break;

          case 6:
            Serial << F("Tune request") << endl;
            break;

          case 7:
            Serial << F("End of exclusive") << endl;
            break;
            
          case 8:
            Serial << F("Timing clock") << endl;
            break;
            
          case 9:
            Serial << F("Reserved (9)") << endl;
            break;

          case 10:
            Serial << F("Start") << endl;
            break;
            
          case 11:
            Serial << F("Continue") << endl;
            break;
            
          case 12:
            Serial << F("Stop") << endl;
            break;
            
          case 13:
            Serial << F("Reserved (13)") << endl;
            break;
            
          case 14:
            Serial << F("Active sensing") << endl;
            break;
            
          case 15:
            Serial << F("Reset") << endl;
            break;
            
          }  // end of switch on system message  
          
        }  // end system message
        break;
      }  // end of switch
    }  // end of if
  else
    Serial << _HEX(c) << endl;
   
}  // end of loop
