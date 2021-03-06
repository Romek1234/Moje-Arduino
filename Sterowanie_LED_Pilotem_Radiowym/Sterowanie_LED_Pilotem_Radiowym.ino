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
     pinMode(diodaLED, OUTPUT);
      pinMode(diodaLEDPlus, OUTPUT);
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
      switch (results.value) {
        
         case 0x99247EBA:
            //Serial.print("srodek OK  ");
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
            
          case 0xD2268818:
           //Serial.print("w prawo");
          // Serial.println(note);
  zmien_w_gore_o_polton();
           break;
  
         case 0x71F9F1D7:
           //Serial.print("w lewo");
          // Serial.println(note);
  zmien_w_dol_o_polton();
             break;
            
            case 0x845E5420:
           //Serial.print("w gore");
          // Serial.println(note);
  zmien_w_gore_o_oktawe();
              break;
              
            case 0xEC9A30D9:
   //Serial.print("w dol");
  // Serial.println(note);
  zmien_w_dol_o_oktawe();
              break;
               
            
              case 0xC38E4620:
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

            // ******* zmniany kana??u MIDI ******
            case 0x3407DE1F: // 1 "jedynka" w????cza prac?? na kanale 1
            chanel = 0x90;
             break;

             case 0x140C2C66: // 2
            chanel = 0x91;
             break;
             
            case 0xAAB48C8B: // 3
            chanel = 0x92;
             break;
             
             case 0x6F59C2E2: // 4
            chanel = 0x93;
             break;
             
             case 0x5853F701: // 5
            chanel = 0x94;
             break;
             
             case 0xBD21F6DA: // 6
            chanel = 0x95;
             break;
             
             case 0x19EC217: // 7
            chanel = 0x96;
             break;

             case 0x1B753386: // 8
            chanel = 0x97;
             break;

             case 0x8C51BBE5: // 9
            chanel = 0x98;
             break;

             case 0xF8E21518: // 9
            chanel = 0x99;
             break;
             
             
             case 0x1772D57C: // mute - wy??acza wszystko
            AllNoteOff();
             break;
             
             case 0xBBC24EA0: // "power czerwony" wy??acza wszystko i przywraca ustawienia poczatkowe
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

                   case 0x854F1F1D: // czerwony w????cza dodatkow?? nute na innym kanale o jeden wy??szym
            //Serial.print("czerwony"); 
            //600Serial.println(note);
            diodaLedPlusStatus = ~diodaLedPlusStatus;
            digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
        if (diodaLedPlusStatus == -1) {
              chanel = chanel +1;
              wlancznute();
              chanel = chanel -1;
      }
      if (diodaLedPlusStatus == LOW) {
              chanel = chanel +1;
              wylancznute();
              chanel = chanel -1;
      }
            delay(50);
            break;
            
                       case 0x522DAE6A: // zielony w????cza dodatkow?? nute na innym kanale o dwa wy??szym
            //Serial.print("zielony"); 
            //600Serial.println(note);
            diodaLedPlusStatus = ~diodaLedPlusStatus;
            digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
        if (diodaLedPlusStatus == -1) {
              chanel = chanel +2;
              wlancznute();
              chanel = chanel -2;
      }
      if (diodaLedPlusStatus == LOW) {
              chanel = chanel +2;
              wylancznute();
              chanel = chanel -2;
      }
            delay(50);
            break;

            case 0x75800B79: // ??????ty w????cza dodatkow?? nute na innym kanale o trzy wy??szym
            //Serial.print("??????ty"); 
            //600Serial.println(note);
            diodaLedPlusStatus = ~diodaLedPlusStatus;
            digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
        if (diodaLedPlusStatus == -1) {
              chanel = chanel +3;
              wlancznute();
              chanel = chanel -3;
      }
      if (diodaLedPlusStatus == LOW) {
              chanel = chanel +3;
              wylancznute();
              chanel = chanel -3;
      }
            delay(50);
            break;

            case 0x9FF5E262: // niebieski w????cza dodatkow?? nute na innym kanale o trzy wy??szym
            //Serial.print("??????ty"); 
            //600Serial.println(note);
            diodaLedPlusStatus = ~diodaLedPlusStatus;
            digitalWrite(diodaLEDPlus, diodaLedPlusStatus);
        if (diodaLedPlusStatus == -1) {
              chanel = chanel -1;
              wlancznute();
              chanel = chanel +1;
      }
      if (diodaLedPlusStatus == LOW) {
              chanel = chanel -1;
              wylancznute();
              chanel = chanel +1;
      }
            delay(50);
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
  //Serial.println(" wykonano g??osn?? procedur?? zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 1;
   if (note > 97){
    note = 36;
  }
  //Serial.println(" wykonano cic?? procedur?? zmien_w_gore_o_polton");
   
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
  //Serial.println(" wykonano g??osn?? procedur?? zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note - 1;
   if (note < 36){
    note = 36;
  }
  //Serial.println(" wykonano cic?? procedur?? zmien_w_gore_o_polton");
   
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
  //Serial.println(" wykonano g??osn?? procedur?? zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 12;
   if (note > 97){
     note = note - 97;
    note = note + 36;
  }
  //Serial.println(" wykonano cic?? procedur?? zmien_w_gore_o_polton");
   
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
  //Serial.println(" wykonano g??osn?? procedur?? zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note - 12;
   if (note < 36 ) { 
    note = 36;
  }
  //Serial.println(" wykonano cic?? procedur?? zmien_w_gore_o_polton");
   
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
  //Serial.println("wys??ano MIDI");
}
void AllNoteOff(){
  Serial.write(0xB0);
  Serial.write(120);
  Serial.write(0);
}
