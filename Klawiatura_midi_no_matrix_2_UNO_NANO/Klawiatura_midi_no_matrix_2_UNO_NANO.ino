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
    {2, {note(C, 2), CHANNEL_1}},
    {3, {note(Db, 2), CHANNEL_1}},
    {4, {note(D, 2), CHANNEL_1}},
    {5, {note(Eb, 2), CHANNEL_1}},
    {6, {note(E, 2), CHANNEL_1}},
    {7, {note(F, 2), CHANNEL_1}},
    {8, {note(Gb, 2), CHANNEL_1}},
    {9, {note(G, 2), CHANNEL_1}},
    {10, {note(Ab, 2), CHANNEL_1}},
    {11, {note(A, 2), CHANNEL_1}},
    {12, {note(Bb, 2), CHANNEL_1}},
    {13, {note(B, 2), CHANNEL_1}},
    //{13, {note(C, 3), CHANNEL_1}},
    //{14, {note(Db, 3), CHANNEL_1}},
   // {15, {note(D, 3), CHANNEL_1}},
    //{16, {note(Eb, 3), CHANNEL_1}},
   // {17, {note(E, 3), CHANNEL_1}},
  //  {18, {note(F, 3), CHANNEL_1}},
   // {19, {note(Gb, 3), CHANNEL_1}},
   //// {20, {note(G, 3), CHANNEL_1}},
   // {21, {note(Ab, 3), CHANNEL_1}},
   // {22, {note(A, 3), CHANNEL_1}},
  //  {23, {note(Bb, 3), CHANNEL_1}},
  //  {A0, {note(B, 3), CHANNEL_1}},
    {A0, {note(C, 3), CHANNEL_1}},
    {A1, {note(Db, 3), CHANNEL_1}},
    {A2, {note(D, 3), CHANNEL_1}},
    {A3, {note(Eb, 3), CHANNEL_1}},
    {A4, {note(E, 3), CHANNEL_1}},
    {A5, {note(F, 3), CHANNEL_1}},
    //{A7, {note(Gb, 4), CHANNEL_1}},
    
  
    
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
