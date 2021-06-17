
#include <MIDI.h>   // Add Midi Library
 
#define LED 13    // Arduino Board LED is on Pin 13
#define LED2 2
#define LED3 3

#define sub_II_to_I 8
int count_sub_II_to_I = 0;
int table_sub_II_to_I[30];

#define super_II_to_I 9
int count_super_II_to_I = 0;
int table_super_II_to_I[30];

#define II_to_I 10
int count_II_to_I = 0;
int table_II_to_I[30];

#define super_I 11
int count_super_I = 0;
int table_super_I[30];
unsigned long BAS_man_I = 0;
unsigned long TREBL_man_I = 0;

#define super_II 12
int count_super_II = 0;
int table_super_II[30];

#define II_to_P 7
int count_II_to_P = 0;
int table_II_to_P[30];

#define I_to_P 6
int count_I_to_P = 0;
int table_I_to_P[30];

#define super_P 5
int count_super_P = 0;
int table_super_P[30];

#define sub_I 4
int count_sub_I = 0;
int table_sub_I[30];


 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);

  pinMode (sub_II_to_I, INPUT_PULLUP); // set board pin ... to intput
  pinMode (super_II_to_I, INPUT_PULLUP);
  pinMode (II_to_I, INPUT_PULLUP);
  pinMode (super_I, INPUT_PULLUP);
  pinMode (super_II, INPUT_PULLUP);
  pinMode (II_to_P, INPUT_PULLUP);
  pinMode (I_to_P, INPUT_PULLUP);
  pinMode (super_P, INPUT_PULLUP);
  pinMode (sub_I, INPUT_PULLUP);
  
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
   if (pitch == 60) {
    digitalWrite(LED,HIGH);  //Turn LED on for note c1
   }
    if (channel == 1) {
      digitalWrite(LED2,HIGH); //Turn LED2 on for all note channel 1
    }

  if (digitalRead(sub_I) == LOW && channel == 1) {
    pitch = pitch - 12;
    //count_sub_I = count_sub_I + 1;
    //table_sub_I[count_sub_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    pitch = pitch + 12;
  }
    
  if (digitalRead(super_I) == LOW && channel == 1) {
       digitalWrite(LED3,HIGH); // //Turn LED3 on for control superoctawe
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_man_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_man_I, pitch - 69);
    }
     pitch = pitch + 12;
    //count_super_I = count_super_I + 1;
    //table_super_I[count_super_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
     pitch = pitch - 12;
  }

  if (digitalRead(super_II) == LOW && channel == 2) {
       digitalWrite(LED3,HIGH); // //Turn LED3 on for control superoctawe
    pitch = pitch + 12;
    //count_super_II = count_super_II + 1;
    //table_super_II[count_super_II] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
     pitch = pitch - 12;
  }
  
  if (digitalRead(II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    //count_II_to_I = count_II_to_I + 1;
    //table_II_to_I[count_II_to_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
  }

  if (digitalRead(super_II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    pitch = pitch + 12;
    //count_super_II_to_I = count_super_II_to_I + 1;
    //table_super_II_to_I[count_super_II_to_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch - 12;
  }

   if (digitalRead(sub_II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    pitch = pitch - 12;
    //count_sub_II_to_I = count_sub_II_to_I + 1;
    //table_sub_II_to_I[count_sub_II_to_I] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch + 12;
  }

    if (digitalRead(II_to_P) == LOW && channel == 3) {
    channel = channel - 1;
    //count_II_to_P = count_II_to_P + 1;
    //table_II_to_P[count_II_to_P] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel + 1;
  }

  if (digitalRead(I_to_P) == LOW && channel == 3) {
    channel = channel - 2;
    //count_I_to_P = count_I_to_P + 1;
    //table_I_to_P[count_I_to_P] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel + 2;
  }

  
    if (digitalRead(super_P) == LOW && channel == 3) {
    pitch = pitch + 12;
    //count_super_P = count_super_P + 1;
    //table_super_P[count_super_P] = pitch;
    MIDI.sendNoteOn (pitch, velocity, channel);
     pitch = pitch - 12;
  }


}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
 
    digitalWrite(LED,LOW);  //Turn LED off
    digitalWrite(LED2,LOW);  //Turn LED2 off 
    digitalWrite(LED3,LOW);  //Turn LED3 off

    if (digitalRead(sub_I) == LOW && channel == 1) {
    pitch = pitch - 12;
    //count_super_I = count_super_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch + 12;
   } 
    //  else if (count_sub_I !=0 ){
      //int pitch_storage = pitch;
      //count_sub_I = count_sub_I + 5;
       //  while (count_sub_I >= 0) {
       //  pitch = table_sub_I[--count_sub_I];
        // MIDI.sendNoteOff (pitch, velocity, channel);
       // }
   //   pitch = pitch_storage;
   // }

  
  if (digitalRead(super_I) == LOW && channel == 1) {
    pitch = pitch + 12;
    //count_super_I = count_super_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 
 //  else if ( count_super_I !=0 ) {
//   
 //   for ( count_super_I; count_super_I >= 0; count_super_I--){
 //     pitch = table_super_I[count_super_I];
 //     MIDI.sendNoteOff (pitch, velocity, channel);
  //    }
     //else if (count_super_I !=0 ){
     // int pitch_storage = pitch;
     // count_super_I = count_super_I + 5;
      //   while (count_super_I >= 0) {
      //   pitch = table_super_I[--count_super_I];
     //    MIDI.sendNoteOff (pitch, velocity, channel);
      //  }
     // pitch = pitch_storage;
   // }

if (digitalRead(super_II) == LOW && channel == 2) {
    pitch = pitch + 12;
   // count_super_II = count_super_II - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 
 //  else if ( count_super_I !=0 ) {
//   
 //   for ( count_super_I; count_super_I >= 0; count_super_I--){
 //     pitch = table_super_I[count_super_I];
 //     MIDI.sendNoteOff (pitch, velocity, channel);
  //    }
     //else if (count_super_II !=0 ){
     // int pitch_storage = pitch;
     // count_super_II = count_super_II + 5;
       //  while (count_super_II >= 0) {
        // pitch = table_super_II[--count_super_II];
        // MIDI.sendNoteOff (pitch, velocity, channel);
       // }
    //  pitch = pitch_storage;
   // }

    
  if (digitalRead(II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    //count_II_to_I = count_II_to_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1; 
   } 
    // else if (count_II_to_I !=0){
     // int pitch_storage = pitch;
      //count_II_to_I = count_II_to_I + 5;
       ////  while (count_II_to_I >= 0) {
       ////  pitch = table_II_to_I[--count_II_to_I];
         MIDI.sendNoteOff (pitch, velocity, channel + 1);
       // }
     // pitch = pitch_storage;
    //}

    if (digitalRead(super_II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    pitch  = pitch + 12;
    //count_super_II_to_I = count_super_II_to_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1; 
    pitch  = pitch - 12;
   } 
     //else if (count_super_II_to_I !=0){
     // int pitch_storage = pitch;
      ////count_super_II_to_I = count_super_II_to_I + 5;
       //  while (count_super_II_to_I >= 0) {
         //pitch = table_super_II_to_I[--count_super_II_to_I];
         //MIDI.sendNoteOff (pitch, velocity, channel + 1);
       // }
    //  pitch = pitch_storage;
    //}

    if (digitalRead(sub_II_to_I) == LOW && channel == 1) {
    channel = channel + 1;
    pitch  = pitch - 12;
    //count_sub_II_to_I = count_sub_II_to_I - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1; 
    pitch  = pitch + 12;
   } 
     //else if (count_sub_II_to_I !=0){
     // int pitch_storage = pitch;
     // count_sub_II_to_I = count_sub_II_to_I + 5;
        // while (count_sub_II_to_I >= 0) {
        // pitch = table_sub_II_to_I[--count_sub_II_to_I];
        // MIDI.sendNoteOff (pitch, velocity, channel + 1);
     //   }
     // pitch = pitch_storage;
    //}

    if (digitalRead(II_to_P) == LOW && channel == 3) {
    channel = channel - 1;
   // count_II_to_P = count_II_to_P - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel + 1; 
   } 
    // else if (count_II_to_P !=0){
    //  int pitch_storage = pitch;
    ///  count_II_to_P = count_II_to_I + 5;
     //    while (count_II_to_P >= 0) {
       //  pitch = table_II_to_P[--count_II_to_P];
         //MIDI.sendNoteOff (pitch, velocity, channel - 1);
       // }
      //pitch = pitch_storage;
    //}

   if (digitalRead(I_to_P) == LOW && channel == 3) {
    channel = channel - 2;
    //count_I_to_P = count_I_to_P - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel + 2; 
   } 
    // else if (count_I_to_P !=0){
     // int pitch_storage = pitch;
      //count_I_to_P = count_I_to_P + 5;
        // while (count_I_to_P >= 0) {
         //pitch = table_I_to_P[--count_I_to_P];
         //MIDI.sendNoteOff (pitch, velocity, channel - 2);
        //}
     // pitch = pitch_storage;
    //}

   if (digitalRead(super_P) == LOW && channel == 3) {
    pitch = pitch + 12;
    //count_super_P = count_super_P - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 

     //else if (count_super_P !=0 ){
     // int pitch_storage = pitch;
      ////count_super_P = count_super_P + 5;
        // while (count_super_P >= 0) {
       //  pitch = table_super_P[--count_super_P];
        // MIDI.sendNoteOff (pitch, velocity, channel);
       // }
     // pitch = pitch_storage;
    //}

} 
      
   
   
