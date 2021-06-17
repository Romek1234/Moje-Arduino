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
// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<8, 5> addresses = {{
  {  36,  44,  52,  60,  68 }, 
  {  37,  45,  53,  61,  69 }, 
  {  38,  46,  54,  62,  70 },
  {  39,  47,  55,  63,  71 }, 
  {  40,  48,  56,  64,  72 },
  {  41,  49,  57,  65,  73 }, 
  {  42,  50,  58,  66,  74 }, 
  {  43,  51,  59,  67,  75 },
}};

NoteButtonMatrix<8, 5> buttonmatrix = {
   
  {5, 6, 7, 8, 9, 10, 11, 12}, // column pins
  {A0, A1, A2, A3, A4}, // row pins
  
  addresses,    // address matrix
  CHANNEL_4,    // channel and cable number
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
