// Klawiatura MIDI do pedału od organów Wiscount Domus Recitative
// Interface Midi for Pedalboard Wiscount Domus Recitative
/**
 * This examples shows how to use a button matrix to read many switches.
 * 
 * @boards  AVR, AVR USB, Nano Every, Due, Nano 33, Teensy 3.x, ESP32
 * 
 * Connections
 * -----------
 * 
 * Connect a 4 × 3 matrix of buttons with the rows to pins 2, 3, 4 and 5, 
 * and the columns to pins 6, 7 and 8.
 * 
 * Pull-up resistors are not necessary, because the internal ones will be used. 
 * 
 * If you want to be able to press multiple buttons at once, add a diode 
 * in series with each button:  
 * @image html Button-matrix.png
 * 
 * Behavior
 * --------
 * 
 * When you press one of the buttons, a note on event for the corresponding note
 * is sent, when you release it, a note off event is sent.
 * 
 * Mapping
 * -------
 *
 * The note numbers are specified in the `addresses` array.
 * Map accordingly in your DAW or DJ software.
 *
 * Written by Pieter P, 24/09/2017  
 * https://github.com/tttapa/Control-Surface
 */

#include <Control_Surface.h>
// Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;// - nie działa
HardwareSerialMIDI_Interface midi = Serial;
//HardwareSerialMIDI_Interface midi = Serial;
//HairlessMIDI_Interface midi;
//USBMIDI_Interface midi;

// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<4, 8> addresses = {{
  {36, 37, 38, 39, 40, 41, 42, 43},
  {44, 45, 46, 47, 48,  49, 50, 51},
  {52, 53, 54, 55, 56, 57, 58, 59},
  {60, 61, 62, 63, 64, 65, 66, 67},
}};

NoteButtonMatrix<4, 8> buttonmatrix = {
  {A0, A1, A2, A3}, // row pins
  {2, 3, 4, 5, 6, 7, 8, 9 }, // column pins
  addresses,    // address matrix
  CHANNEL_1,    // channel and cable number
};

void setup() {
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}
