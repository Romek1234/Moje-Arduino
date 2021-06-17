#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
 
#define diodaPin 13
#define diodaLED 12
#define diodaLEDPlus 10
#define WKplus 9
#define WKminus 8
int note = 60;
int chanel = 0x90;


int diodaStatus = LOW;
int diodaLedStatus = LOW;
int diodaLedPlusStatus = LOW;
int SuboctaveStatus = LOW;
int SuperquintStatus = LOW;
int SubquintStatus = LOW;

 
void setup() {
   Serial.begin(31250);
    irrecv.enableIRIn();
// Definiowanie pinów jako wyściowych 
    pinMode(diodaPin, OUTPUT);
    pinMode(diodaLED, OUTPUT);
    pinMode(diodaLEDPlus, OUTPUT);
    pinMode(WKplus, OUTPUT);
    digitalWrite(WKplus, HIGH);
    pinMode(WKminus, OUTPUT);
    digitalWrite(WKminus, HIGH);
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
               
            
              case 0x5985AF7D:
            //Serial.print(" > ")nacisnieto kanał w górę na pilocie;
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
            
                  case 0x758276C3:
            //Serial.print(" < ") // nacisnięto kanał w dół na pilocie;
            //600Serial.println(note);
            SuboctaveStatus = ~SuboctaveStatus;
            digitalWrite(diodaLEDPlus, SuboctaveStatus);           
        if (SuboctaveStatus == -1) {
              wlanczSuboctave();
      }
      if (SuboctaveStatus == LOW) {
              wylanczSuboctave();
      }
            delay(150);
            break;      

      case 0xFED5C857:
            //Serial.print(" trójkąt ") // nacisnięto trójkąt w gótę na pilocie;
            //600Serial.println(note);
            SuperquintStatus = ~SuperquintStatus;           
        if (SuperquintStatus == -1) {
              wlanczSuperquint();
      }
      if (SuperquintStatus == LOW) {
              wylanczSuperquint();
      }
            delay(150);
            break;

      case 0x65B3631F:
            //Serial.print(" trójkąt ") // nacisnięto trójkąt w dół na pilocie;
            //600Serial.println(note);
            SubquintStatus = ~SubquintStatus;           
        if (SubquintStatus == -1) {
              wlanczSubquint();
      }
      if (SubquintStatus == LOW) {
              wylanczSubquint();
      }
            delay(150);
            break;
      

            // ******* zmniany kanału MIDI ******
            case 0x3407DE1F: // 1 "jedynka" włącza pracę na kanale 1
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
             
             
             case 0x1772D57C: // mute - wyłacza wszystko
            AllNoteOff();
             break;
             
              case 0xC38E4620: // głosniej ( + na pilocie)
            impulsPlus();
             break;

              case 0x7C9775D0: // ciszej ( - na pilocie)
            impulsMinus();
             break;
             
             case 0xBBC24EA0: // "power czerwony" wyłacza wszystko i przywraca ustawienia poczatkowe
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

                   case 0x854F1F1D: // czerwony włącza dodatkową nute na innym kanale o jeden wyższym
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
            
                       case 0x522DAE6A: // zielony włącza dodatkową nute na innym kanale o dwa wyższym
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

            case 0x75800B79: // żółty włącza dodatkową nute na innym kanale o trzy wyższym
            //Serial.print("żółty"); 
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

            case 0x9FF5E262: // niebieski włącza dodatkową nute na innym kanale o trzy wyższym
            //Serial.print("żółty"); 
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
      if (SuboctaveStatus == -1) {
      wylanczSuboctave();
      }
      if (SuperquintStatus == -1) {
      wylanczSuperquint();
      }
      if (SubquintStatus == -1) {
      wylanczSubquint();
      }
  wylancznute();
  note = note + 1;
   if (note > 105){
    note = 36;
  }
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  if (SuboctaveStatus == -1) {
    wlanczSuboctave();
    }
  if (SuperquintStatus == -1) {
    wlanczSuperquint();
    }
  if (SubquintStatus == -1) {
    wlanczSubquint();
    }
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 1;
   if (note > 105){
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
   if (SuboctaveStatus == -1) {
      wylanczSuboctave();
      }
   if (SuperquintStatus == -1) {
      wylanczSuperquint();
      }
   if (SubquintStatus == -1) {
      wylanczSubquint();
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
   if (SuboctaveStatus == -1) {
    wlanczSuboctave();
    }
   if (SuperquintStatus == -1) {
    wlanczSuperquint();
      }
   if (SubquintStatus == -1) {
    wlanczSubquint();
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
  if (SuboctaveStatus == -1) {
      wylanczSuboctave();
  }
  if (SuperquintStatus == -1) {
      wylanczSuperquint();
  }
      if (SubquintStatus == -1) {
      wylanczSubquint();
  }
  wylancznute();
  note = note + 12;
  if (note > 105) { 
    note = note - 105;
    note = note + 36;
  }
  
  wlancznute();
  if (diodaLedStatus == -1) {
    wlanczsuperoctave();
    }
  if (SuboctaveStatus == -1) {
      wlanczSuboctave();
  }
  if (SuperquintStatus == -1) {
      wlanczSuperquint();
   }
      if (SubquintStatus == -1) {
      wlanczSubquint();
   }  
  //Serial.println(" wykonano głosną procedurę zmien_w_gore_o_polton");
   }
  if (diodaStatus == LOW) {
  note = note + 12;
   if (note > 105){
     note = note - 105;
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
  if (SuboctaveStatus == -1) {
      wylanczSuboctave();
  }
  if (SuperquintStatus == -1) {
      wylanczSuperquint();
   }
      if (SubquintStatus == -1) {
      wylanczSubquint();
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
  if (SuboctaveStatus == -1) {
      wlanczSuboctave();  
  }
  if (SuperquintStatus == -1) {
      wlanczSuperquint();
      }
      if (SubquintStatus == -1) {
      wlanczSubquint();
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

void wlanczSuboctave() {
  //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(chanel, note - 12, 0x45);
    //Serial.println("wlonczenie nuty");
    delay(100);      
}
void wylanczSuboctave() {
//Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(chanel, note - 12 , 0x00);
    //Serial.println("wylonczenie nuy");
    delay(100);
    } 

    void wlanczSuperquint() {
  //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(chanel, note + 7, 0x45);
    //Serial.println("wlonczenie nuty");
    delay(100);      
}
void wylanczSuperquint() {
//Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(chanel, note + 7 , 0x00);
    //Serial.println("wylonczenie nuy");
    delay(100);
    }          

void wlanczSubquint() {
  //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
    noteOn(chanel, note - 7, 0x45);
    //Serial.println("wlonczenie nuty");
    delay(100);      
}
void wylanczSubquint() {
//Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
    noteOn(chanel, note - 7 , 0x00);
    //Serial.println("wylonczenie nuy");
    delay(100);
    } 
void impulsPlus(){
digitalWrite(WKplus, LOW); 
delay(300);
digitalWrite(WKplus, HIGH); 
delay(150);
}

void impulsMinus(){
digitalWrite(WKminus, LOW); 
delay(300);
digitalWrite(WKminus, HIGH); 
delay(150);      
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
