#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
 
#define diodaPin 13
#define diodaLED 12
#define diodaLEDPlus 10
int note = 60;
int chanel = 0x90;


int diodaStatus = LOW;
int diodaLedStatus = LOW;
int diodaLedPlusStatus = LOW;
 
void setup() {
   Serial.begin(31250);
    irrecv.enableIRIn();
 
    pinMode(diodaPin, OUTPUT);
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
      switch (results.value) {
         case 0x6170A857:
            //Serial.print("srodek  ");
            //600Serial.println(note);
            diodaStatus = ~diodaStatus;
            digitalWrite(diodaPin, diodaStatus);
        if (diodaStatus == -1) {
              wlancznute();
      }
      if (diodaStatus == LOW) {
              wylancznute();
              wylanczsuperoctave();
      }
            delay(150);
            break;
            
          case 0x617038C7:
           //Serial.print("w prawo");
          // Serial.println(note);
  zmien_w_gore_o_polton();
           break;
  
         case 0x6170D827:
           //Serial.print("w lewo");
          // Serial.println(note);
  zmien_w_dol_o_polton();
             break;
            
            case 0x6170D02F:
           //Serial.print("w gore");
          // Serial.println(note);
  zmien_w_gore_o_oktawe();
              break;
              
            case 0x617030CF:
   //Serial.print("w dol");
  // Serial.println(note);
  zmien_w_dol_o_oktawe();
              break;
               
            
              case 0x6170B04F:
            //Serial.print("V+");
            //600Serial.println(note);
            diodaLedStatus = ~diodaLedStatus;
            digitalWrite(diodaLED, diodaLedStatus);
        if (diodaLedStatus == -1) {
              wlanczsuperoctave();
      }
      if (diodaLedStatus == LOW) {
              wylanczsuperoctave();
      }
            delay(150);
            break;

            // ******* zmniany kanału MIDI ******
            case 0x6170807F: // jedynka - 1 kanał
            chanel = 0x90;
             break;

            case 0x617040BF: // dwójka - 2 kanał
            chanel = 0x91;
             break;
             
            case 0x6170C03F: // trójka - 3 kanał
            chanel = 0x92;
             break;
             
            case 0x4AB0F7B5: // czwórka
            chanel = 0x93;
             break;

            case 0x4CB0FADF: // piątka
            chanel = 0x94;
             break;

             case 0xF92C972F: // sóstka
            chanel = 0x95;
             break;

             case 0x4AB0F7B7: // siódemka
            chanel = 0x96;
             break;

             case 0xED0E573B: // ósemka
            chanel = 0x97;
             break;

             case 0x4AB0F7B5: // dziewiątka
            chanel = 0x98;
             break;

             
             
             case 0x6170F807: // mute - wyłacza wszystko
            AllNoteOff();
             break;
             
             case 0x617048B7: // power czerwony wyłacza wszystko i przywraca ustawienia poczatkowe
          AllNoteOff();
          note = 60;
          chanel = 0x90;
          diodaStatus = LOW;
          diodaLedStatus = LOW;
          diodaLedPlusStatus = LOW;
          digitalWrite(diodaPin, diodaStatus);
          digitalWrite(diodaLED, diodaLedStatus);
          digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
          break;

                   case 0xF92C972D: // włącza i wyłącza dodatkowy dźwiek na innym kanale
            //Serial.print("play");
            //600Serial.println(note);
            diodaLedPlusStatus = ~diodaLedPlusStatus;
            digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
        if (diodaLedPlusStatus == -1) {
              wlancznute();
      }
      if (diodaLedPlusStatus == LOW) {
              wylancznute();
      }
            delay(150);
            break;

         }
 
   irrecv.resume();
   }
 }
//*****************************************************
void zmien_w_gore_o_polton(){
  if (diodaStatus == -1) {
    if (diodaLedStatus == -1) {
      wylanczsuperoctave();
      }
  wylancznute();
  note = note + 1;
   if (note > 97){
    note = 36;
  }
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 1;
   if (note > 97){
    note = 36;
  }
  //Serial.println(" wykonano cicą procedurę zmien_w_gore_o_polton");
   
   }
}
//*******************************************************  
void zmien_w_dol_o_polton(){
  if (diodaStatus == -1) {
    if (diodaLedStatus == -1) {
      wylanczsuperoctave();
      }
  wylancznute();
  note = note - 1;
   if (note < 36){
    note = 36;
  }
  
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note - 1;
   if (note < 36){
    note = 36;
  }
  //Serial.println(" wykonano cicą procedurę zmien_w_gore_o_polton");
   
   }
} 
//************************************************** 
void zmien_w_gore_o_oktawe() {

  if (diodaStatus == -1) {
    if (diodaLedStatus == -1) {
      wylanczsuperoctave();
  }
  wylancznute();
  note = note + 12;
  if (note > 97) { 
    note = note - 97;
    note = note + 36;
  }
  
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 12;
   if (note > 97){
     note = note - 97;
    note = note + 36;
  }
  //Serial.println(" wykonano cicą procedurę zmien_w_gore_o_polton");
   
   }
} 
//****************************************************
void zmien_w_dol_o_oktawe() {
  if (diodaStatus == -1) {
    if (diodaLedStatus == -1) {
      wylanczsuperoctave();
  }
  wylancznute();
  note = note - 12;
  if (note < 36 ) { 
    note = 36;
  }
  
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note - 12;
   if (note < 36 ) { 
    note = 36;
  }
  //Serial.println(" wykonano cicą procedurę zmien_w_gore_o_polton");
   
   }
} 


//********************************************************** 
void wlancznute() {
//Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(chanel, note, 0x45);
    //Serial.println("wlonczenie nuty");
    delay(100);
  }   
void wylancznute() {
//Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(chanel, note, 0x00);
    //Serial.println("wylonczenie nuty");
    delay(100);
    }
void wlanczsuperoctave() {
  //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(chanel, note + 12, 0x45);
    //Serial.println("wlonczenie nuty");
    delay(100);      
}
void wylanczsuperoctave() {
//Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(chanel, note +12 , 0x00);
    //Serial.println("wylonczenie nuy");
    delay(100);
    }          

    
// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
  //Serial.println("wysłano MIDI");
}
void AllNoteOff(){
  Serial.write(0xB0);
  Serial.write(120);
  Serial.write(0);
}
