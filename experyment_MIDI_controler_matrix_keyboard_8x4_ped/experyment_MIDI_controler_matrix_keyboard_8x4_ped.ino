#include <Controller.h>
// TEŻ DZIAŁA Z pEDAŁEM OD WISCONT dOMUS RECITATIVE
 
/*
Diody przewodzą w kierunku pinów A0 A1...

This is an example of the "ButtonMatrix" class of the MIDI_controller library.
Connect a 4 × 3 matrix of buttons with the rows to pins 2, 3, 4 and 5, 
and the columns to pins 6, 7 and 8.
Pull-up resistors are not necessary, because the internal ones will be used. 
If you want to be able to press multiple buttons at once, add a diode 
in series with each button, as shown in the schematic on the Wiki:
https://github.com/tttapa/MIDI_controller/wiki/Hardware
The note numbers are specified in the 'addresses' array.
Map accordingly in your DAW or DJ software.
Written by tttapa, 24/09/2017
https://github.com/tttapa/MIDI_controller
*/

#include "MIDI_Controller.h" // Include the library
//USBMIDI_Interface midi;  // Instantiate a MIDI Interface to use, dziala z Leonardo
//HairlessMIDI_Interface midi;
//USBDebugMIDI_Interface midiInterface(115200); // dzialające
//USBDebugMIDI_Interface(unsigned long 115200);
//StreamDebugMIDI_Interface;
//SerialDebugMIDI_Interface;
//HardwareSerialDebugMIDI_Interface(Serial,115200);
//SoftwareSerialDebugMIDI_Interfa
//HardwareMIDI_Interface midi;

const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t addresses[4][8] = {   // 4 wiersze 8 kolumn the note numbers corresponding to the buttons in the matrix
  {  36,  37,  38, 39, 40, 41, 42, 43 },
  {  44,  45,  46, 47, 48, 49, 50, 51 },
  {  52,  53,  54, 55, 56, 57, 58, 59 },
  {  60,  61,  62, 63, 64, 65, 66, 67 }
};

const uint8_t addresses1[2][2] = {   // 4 wiersze 8 kolumn the note numbers corresponding to the buttons in the matrix
  {  36,  37},
  {  44,  45}
  
};

// Create a new instance of the class 'ButtonMatrix', called 'buttonmatrix', with dimensions 4 rows and 3 columns, with the rows connected to pins 2, 3, 4 and 5
// and the columns connected to pins 6, 7 and 8, that sends MIDI messages with the notes specified in 'addresses' on MIDI channel 1, with velocity 127
ButtonMatrix<4, 8> buttonmatrix( {A0, A1, A2, A3}, {2, 3, 4, 5, 6, 7, 8, 9}, addresses, 1, velocity);
ButtonMatrix<2, 2> buttonmatrix1( {A4, A5}, {11,12}, addresses1, 3, velocity);

void setup() {}

void loop() {
  // Refresh the buttons (check whether the states have changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}
