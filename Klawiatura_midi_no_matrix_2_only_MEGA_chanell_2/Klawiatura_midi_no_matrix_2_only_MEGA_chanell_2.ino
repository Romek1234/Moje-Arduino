/**
 * for ATmega1284p or Arduino mega
 * @brief   This example demonstrates the use of push buttons that send note 
 *          events.
 * 
 * ### Connections
 * 
 *  - 2:  momentary push button (to ground)
 *  - 3:  momentary push button (to ground)
 * 
 * The internal pull-up resistors for the buttons will be enabled automatically.
 * 
 * ### Behavior
 * 
 * Pressing the first button will send note on/off events on middle C.
 * Pressing the second button will send note on/off events for middle C sharp.
 * 
 * Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */

// Include the Control Surface library
#include <Control_Surface.h>

// Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midi;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;

// Instantiate the momentary push buttons that send out MIDI Note events.
NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano
    {2, {note(C, 2), CHANNEL_2}},
    {3, {note(Db, 2), CHANNEL_2}},
    {4, {note(D, 2), CHANNEL_2}},
    {5, {note(Eb, 2), CHANNEL_2}},
    {6, {note(E, 2), CHANNEL_2}},
    {7, {note(F, 2), CHANNEL_2}},
    {8, {note(Gb, 2), CHANNEL_2}},
    {9, {note(G, 2), CHANNEL_2}},
    {10, {note(Ab, 2), CHANNEL_2}},
    {11, {note(A, 2), CHANNEL_2}},
    {12, {note(Bb, 2), CHANNEL_2}},
    {A15, {note(B, 2), CHANNEL_2}},
    {14, {note(C, 3), CHANNEL_2}},
    {15, {note(Db, 3), CHANNEL_2}},
    {16, {note(D, 3), CHANNEL_2}},
    {17, {note(Eb, 3), CHANNEL_2}},
    {18, {note(E, 3), CHANNEL_2}},
    {19, {note(F, 3), CHANNEL_2}},
    {20, {note(Gb, 3), CHANNEL_2}},
    {21, {note(G, 3), CHANNEL_2}},
    {22, {note(Ab, 3), CHANNEL_2}},
    {23, {note(A, 3), CHANNEL_2}},
    {24, {note(Bb, 3), CHANNEL_2}},
    {25, {note(B, 3), CHANNEL_2}},
    {26, {note(C, 4), CHANNEL_2}},
    {27, {note(Db, 4), CHANNEL_2}},
    {28, {note(D, 4), CHANNEL_2}},
    {29, {note(Eb, 4), CHANNEL_2}},
    {30, {note(E, 4), CHANNEL_2}},
    {31, {note(F, 4), CHANNEL_2}},
    {32, {note(Gb, 4), CHANNEL_2}},
    {33, {note(G, 4), CHANNEL_2}},
    {34, {note(Ab, 4), CHANNEL_2}},
    {35, {note(A, 4), CHANNEL_2}},
    {36, {note(Bb, 4), CHANNEL_2}},
    {37, {note(B, 4), CHANNEL_2}},
    {38, {note(C, 5), CHANNEL_2}},
    {39, {note(Db, 5), CHANNEL_2}},
    {40, {note(D, 5), CHANNEL_2}},
    {41, {note(Eb, 5), CHANNEL_2}},
    {42, {note(E, 5), CHANNEL_2}},
    {43, {note(F, 5), CHANNEL_2}},
    {44, {note(Gb, 5), CHANNEL_2}},
    {45, {note(G, 5), CHANNEL_2}},
    {46, {note(Ab, 5), CHANNEL_2}},
    {47, {note(A, 5), CHANNEL_2}},
    {48, {note(Bb, 5), CHANNEL_2}},
    {49, {note(B, 5), CHANNEL_2}},
    {50, {note(C, 6), CHANNEL_2}},
    {51, {note(Db, 6), CHANNEL_2}},
    {52, {note(D, 6), CHANNEL_2}},
    {53, {note(Eb, 6), CHANNEL_2}},
    {A0, {note(E, 6), CHANNEL_2}},
    {A1, {note(F, 6), CHANNEL_2}},
    {A2, {note(Gb, 6), CHANNEL_2}},
    {A3, {note(G, 6), CHANNEL_2}},
    {A4, {note(Ab, 6), CHANNEL_2}},
    {A5, {note(A, 6), CHANNEL_2}},
    {A6, {note(Bb, 6), CHANNEL_2}},
    {A7, {note(B, 6), CHANNEL_2}},
    {A8, {note(C, 7), CHANNEL_2}},
    {A9, {note(Db, 7), CHANNEL_2}},
    {A10, {note(D, 7), CHANNEL_2}},
    {A11, {note(Eb, 7), CHANNEL_2}},
    {A12, {note(E, 7), CHANNEL_2}},
    {A13, {note(F, 7), CHANNEL_2}},
    {A14, {note(Gb, 7), CHANNEL_2}},
    
    
  
    
};

void setup() {
    // Initialize everything
    Control_Surface.begin();
    midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();
}

void loop() {
    // Update the control surface
    Control_Surface.loop();
    midiser.update();
}
