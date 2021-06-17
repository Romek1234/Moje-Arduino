#include <Control_Surface.h>

//USBMIDI_Interface midi;
//HardwareSerialMIDI_Interface serialmidi = {Serial, MIDI_BAUD};
HairlessMIDI_Interface midi;
// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<4, 8> addresses = {{
{ 36, 37, 38, 39, 40, 41, 42, 43 },
{ 44, 45, 46, 47, 48, 49, 50, 51 },
{ 52, 53, 54, 55, 56, 57, 58, 59 },
{ 60, 61, 62, 63, 64, 65, 66, 67 },
}};

NoteButtonMatrix<4, 8> buttonmatrix = {
{A0, A1, A2, A3}, // row pins
{3, 4, 5, 6, 7, 8, 9, 10}, // column pins
addresses, // address matrix
CHANNEL_1, // channel and cable number
};

void setup() {
Control_Surface.begin();
}

void loop() {
Control_Surface.loop();
}
