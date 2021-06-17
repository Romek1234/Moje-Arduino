#include <PCF8574.h>
#include <Wire.h>
#include <EEPROM.h>

PCF8574 expander1;
PCF8574 expander2;
PCF8574 expander3;
PCF8574 expander4;
PCF8574 expander5;
PCF8574 expander6;
PCF8574 expander7;
PCF8574 expander8;
PCF8574 expander9;
PCF8574 expander10;
PCF8574 expander11;
PCF8574 expander12;

const int cmdOn = 0x93; // definicja stałej okresłajacej komendę noteON for chanel 4 ( 0x80 dla kanał 1)
const int cmdOff = 0x83; // definicja stałej okresłajacej komendę noteON for for chanel 4 ( 0x80 dla kanał 1)

byte a;
byte b;
// byte c;
// int value;
//byte b2;
//byte b3;
//byte b6;
//byte b7;
//byte b10;

byte nastawa_expander1[6];
byte nastawa_expander4[6];
byte nastawa_expander5[6];
byte nastawa_expander8[6];
byte nastawa_expander9[6];

byte cresc_expander1[20];
byte cresc_expander4[20];
byte cresc_expander5[20];
byte cresc_expander8[20];
byte cresc_expander9[20];



 // byte value1_5;
 // byte value1_6;
 // byte value1_7;
 // byte value2_5;
 // byte value2_6;
 // byte value2_7;
  // int stanReg1 = 0;
 // int stanReg2 = 0;
 
// the setup function runs once when you press reset or power the board
void setup() {
   expander1.begin(0x20); //   expander.begin(0x20) dla wersji A
   expander2.begin(0x21); 
   expander3.begin(0x22); 
   expander4.begin(0x23); 
   expander5.begin(0x24); 
   expander6.begin(0x25); 
   expander7.begin(0x26); 
   expander8.begin(0x27);  
   expander9.begin(0x38); //   expander.begin(0x38) dla wersji B
   expander10.begin(0x39);
   expander11.begin(0x3A);
   expander12.begin(0x3B);
   
  // initialize digital pin's for OUTPUT or INPUT
  //  pinMode(13, OUTPUT); //dioda arduino
  //  pinMode(12, OUTPUT); 
  //  pinMode(3, INPUT_PULLUP); 
  //  pinMode(4, INPUT_PULLUP); 

  pinMode(8, INPUT_PULLUP); //set
  
  pinMode(9, INPUT_PULLUP); //set to EPROM

  pinMode(10, INPUT_PULLUP); // jesli LOW to zapis do eprom prog crescendo

  
  pinMode(11, INPUT_PULLUP); // jesli LOW to programowanie crescendo
  
// Odczyt nastaw z EPROM-u dla WK
 for (int i = 0; i < 6; i++){
  nastawa_expander1[i] = EEPROM.read(i + 10);
  nastawa_expander4[i] = EEPROM.read(i + 20);
  nastawa_expander5[i] = EEPROM.read(i + 30);
  nastawa_expander8[i] = EEPROM.read(i + 40);
  nastawa_expander9[i] = EEPROM.read(i + 50);
} 
// Odczyt nastaw z EPROM-u dla crescendo
 for (int i = 0; i < 20; i++){
  cresc_expander1[i] = EEPROM.read(i + 100);
  cresc_expander4[i] = EEPROM.read(i + 125);
  cresc_expander5[i] = EEPROM.read(i + 150);
  cresc_expander8[i] = EEPROM.read(i + 175);
  cresc_expander9[i] = EEPROM.read(i + 200);
} 

                // Ustawienia wyjść (out) expanderów
 for (int i=0; i<8; i++){
  expander1.pinMode(i, OUTPUT); // ustawia piny expandera nr 1 jako wyjścia - sterowanie diodami i elektromagnesami głosowymi
 }       
 for (int i=0; i<8; i++){
  expander4.pinMode(i, OUTPUT); // ustawia piny expandera nr 4 jako wyjścia - sterowanie diodami i elektromagnesami głosowymi
 }       
 for (int i=0; i<8; i++){
  expander5.pinMode(i, OUTPUT); // ustawia piny expandera nr 5 jako wyjścia - elektromagnesy głosowe
 }       
 for (int i=0; i<8; i++){
  expander8.pinMode(i, OUTPUT); //ustawia piny expandera nr 8 jako wyjścia - elektromagnesy głosowe
 }       
 for (int i=0; i<8; i++){
  expander9.pinMode(i, OUTPUT); // ustawia piny expandera nr 9 jako wyjścia - elektromagnesy głosowe
 }       
 for (int i=0; i<8; i++){
  expander12.pinMode(i, OUTPUT); //ustawia piny expandera nr 12 jako wyjścia (lamoki WK 1 - WK6, C, CR)
 }       
 
              // Ustawienia wejść (in) expanderów
  for (int i=0; i<8; i++){
      expander2.pinMode(i, INPUT_PULLUP); //ustawia piny expandera nr 2 jako wejscia i podciaga je do HIGH - manubria registrowe
  }    
  for (int i=0; i<8; i++){
      expander3.pinMode(i, INPUT_PULLUP); // ustawia piny expandera nr 3 jako wejscia manubria registrowe
  }    
   for (int i=0; i<8; i++){
      expander6.pinMode(i, INPUT_PULLUP); // ustawia piny expandera nr 6 jako wejscia manubria registrowe
  }    
   for (int i=0; i<8; i++){
      expander7.pinMode(i, INPUT_PULLUP); // ustawia piny expandera nr 7 jako wejscia manubria registrowe
  }    
   for (int i=0; i<8; i++){
      expander10.pinMode(i, INPUT_PULLUP); // ustawia piny expandera nr 10 jako wejsciamanubria registrowe
  }    
   for (int i=0; i<8; i++){
      expander11.pinMode(i, INPUT_PULLUP); // ustawia piny expandera nr 1 jako wejscia
                                           // przyciski WK 1- WK6, C, CR 
  }    

  // ustawienia startowe expanderów
 expander1.write(0); 
 expander4.write(0); 
 expander5.write(0); 
 expander8.write(0);
 expander9.write(0);
 expander12.write(64);
  
  Serial.begin(31250); //Ustawienie prędkości transmisji (dla Midi Serial.begin(31250), dla monitora portu szeregowego Serial.begin(9600)
  // Serial.println("Setzer Ver.2");
  
} 

// the loop function runs over and over again forever

void loop()
{
  zmiana_registrow();
 
  if (digitalRead(8) == LOW){
    delay(10);
    memory_WK(); 
    // Serial.println("memory");
  }
  else{  
    zmiana_WK();
    // Serial.println("zmiana WK");
  }
  
   if (digitalRead(9) == LOW){ // przycisk 9 włącza zapis nastawien do EPROM
    delay(10);
    set_to_EPROM(); 
    while (digitalRead(9) == LOW) {} // pusta pętla while zapobiegająca ponownemu wpisowi do eprom
    delay(10);
   }
   
   if (digitalRead(10) == LOW){ // przycisk 10 włącza zapis nastawien cresc do EPROM
    delay(10);
    cresc_to_EPROM(); 
    while (digitalRead(10) == LOW) {} // pusta pętla while zapobiegająca ponownemu wpisowi do eprom
    delay(10);
   }
   
   if (digitalRead(11) == LOW){ // przycisk 11 włącza programowanie cresc
    delay(10);
    prog_crescendo(); 
   }
}


/*

 
  //sprawdzanie stanu przycisków
//  byte value3 = digitalRead(3); // WK 1
//  byte value4 = digitalRead(4); // WK 2
//  byte value8 = digitalRead(8); // Set
  
 // jesli wcisniety WK1 i set - zapis stanu registrów do zmiennej stan_reg1
  //if (value3 == LOW && value8 == LOW){
//stanReg1 = spr_reg();
 //   // Serial.println("Zapamietano stan registrów dla WK-1");
 //   // Serial.println(stanReg1); 
 // }
 // jesli wcisniety WK2 i set - zapis stanu registrów do zmiennej stan_reg2 
 // if (value4 == LOW && value8 == LOW){
stanReg2 = spr_reg(); 
  
 //   // Serial.println("Zapamietano stan registrów dla WK-2");
 //   // Serial.println(stanReg2);
//  }
  // WK1
//  if (value3 == LOW){
//  digitalWrite(13, LOW); // zapala diode WK1
//  digitalWrite(12, HIGH);
//  ust_wyj(stanReg1);
//  // Serial.println("Włączono WK-1");
//  // Serial.println(stanReg1);
//  }
//  // turn the LED on (HIGH is the voltage level)
//  delay(100);                       // wait for a second
  // WK2
 // if (value4 == LOW){
 // digitalWrite(13, HIGH);
 // digitalWrite(12, LOW);  // zapala diodę WK2
//  ust_wyj(stanReg2);
//  // Serial.println("Włączono WK-2");
 // // Serial.println(stanReg2);
 // }
  // turn the LED on (HIGH is the voltage level)
 // delay(100);                       // wait for a second
//}


// ---- koniec sekcji loop-----
// ---- rozpoczyna sie obszar funkcji 


//funkcja zapisu stanu registrów
int spr_reg()
{
  int a = 0;
  
  // jesli wlączony register 1
  if (expander1.digitalRead(0) == LOW){
    bitSet(a,0);
  }
  else{
    bitClear(a,0);
  }
    // jesli wlączony register 2
  if (expander.digitalRead(1) == LOW) {
    bitSet(a,1);
  }
   else{
    bitClear(a,1);
  }
    // jesli wlączony register 3
  if (expander.digitalRead(2) == LOW){
    bitSet(a,2);
  }

  else{
    bitClear(a,2);
  }
    // jesli wlączony register 3
  if (expander.digitalRead(3) == LOW){
    bitSet(a,2);
  }

  else{
    bitClear(a,2);
  }
  // Serial.println("Odczytano stan registrów");
  // Serial.println(a);
  return a;
  }
  
// ustawienie wyjść do sterowania elektromagnesami w/g stałej value_sum
void ust_wyj(int stan_reg){
  if bitRead(stan_reg,0){
       expander.digitalWrite(4,LOW); // jeśli najmniejznaczacy bit jest ustawiony włącz elektromagnes nr  1 
  }
    else{
      expander.digitalWrite(4,HIGH);
    }
    if bitRead(stan_reg,1){
       expander.digitalWrite(5,LOW); // włącza elektromagness nr 2
  }
    else{
      expander.digitalWrite(5,HIGH);
    }
    if bitRead(stan_reg,2){
       expander.digitalWrite(6,LOW); // włącza elektromagnes nr 3
       
  }
    else{
      expander.digitalWrite(6,HIGH);
    } 
    if bitRead(stan_reg,3){
       expander.digitalWrite(7,LOW); // włącza elektromagnes nr 3
       
  }
    else{
      expander.digitalWrite(7,HIGH);
    } 
    
}
*/

// funkcja zmienia stan registru po przycisnienciu manubrium i wysyła komunikat midi
 void zmiana_registrow() {
  
 // I para expanderów - sprawdzanie pinów expandera nr 2 i ustaiwanie pinów expandera nr 1
   for (int i=0; i<8; i++){
      
       if (expander2.digitalRead(i) == LOW) { 
        delay(20);
       
                   expander1.toggle(i);
             if (expander1.digitalRead(i) == HIGH){
                noteSend(cmdOn, i+36, 0x45);
             }
             else{
                noteSend(cmdOff, i+36, 0x00);
             }
              delay(300);
           // while (expander2.digitalRead(i)) {}
      
          //a = expander1.read();
          // Serial.println("stan registrów na 2-1");
          // Serial.println(a);
          // Serial.println(b2); 
          }
    }   
  
 // II para expanderów - sprawdzanie pinów expandera nr 3 i ustaiwanie pinów expandera nr 4   
    for (int i=0; i<8; i++){
      
      if (expander3.digitalRead(i) == LOW) { 
        delay(20);

             expander4.toggle(i);
            if (expander4.digitalRead(i) == HIGH){
                noteSend(cmdOn, i+44, 0x45);
             }
             else{
                noteSend(cmdOff, i+44, 0x00);
             }
              delay(300);
          
        // while (expander3.digitalRead(i)) {}
          // a = expander4.read();
          // Serial.println("stan registrów na 3-4");
          // Serial.println(a);
          // Serial.println(b); 
          
     }  
   }
   
// III para expanderów -  sprawdzanie pinów expandera nr 6 i ustaiwanie pinów expandera nr 5     
    for (int i=0; i<8; i++){
      
      if (expander6.digitalRead(i) == LOW) { 
        delay(20);
          expander5.toggle(i);
          if (expander5.digitalRead(i) == HIGH){
                noteSend(cmdOn, i+52, 0x45);
             }
             else{
                noteSend(cmdOff, i+52, 0x00);
             }
              delay(300);
        //  while (expander6.digitalRead(i)) {}
        //  a = expander5.read();
          // Serial.println("stan registrów na 6-5");
          // Serial.println(a);
          // Serial.println(b6); 
         
     }  
   }
   

// IV para expanderów - sprawdzanie pinów expandera nr 7 i ustaiwanie pinów expandera nr 8     
    for (int i=0; i<8; i++){
      
      if (expander7.digitalRead(i) == LOW) { 
        delay(20);
          expander8.toggle(i);
          if (expander8.digitalRead(i) == HIGH){
                noteSend(cmdOn, i+60, 0x45);
             }
             else{
               noteSend(cmdOff, i+60, 0x00);
             }
              delay(300);
            // while (expander7.digitalRead(i)) {} 
          //a = expander8.read();
          // Serial.println("stan registrów na 7-8");
          // Serial.println(a);
          // Serial.println(b7); 
         
     }  
   }     
   
 // V para expanderów - sprawdzanie pinów expandera nr 10 i ustaiwanie pinów expandera nr 9    
    for (int i=0; i<8; i++){
      
      if (expander10.digitalRead(i) == LOW) { 
        delay(20);
         expander9.toggle(i);
         
           if (expander9.digitalRead(i) == HIGH){
                noteSend(cmdOn, i + 68, 0x45);
             }
             else{
                noteSend(cmdOff, i + 68, 0x00);
             }
              delay(300);
           //   while (expander10.digitalRead(i)) {}
          // a = expander9.read();
          // Serial.println("stan registrów na 10-9");
          // Serial.println(a);
          // Serial.println(b10); 
        
     }  
   }
 } 

// ************** procedura zmian WK *****************     
 void zmiana_WK(){
 b = expander11.read();    
    
// włączenie WK
  for (int i=0; i<8; i++){
      if (expander11.digitalRead(i) == LOW) { // sprawdza piny expandera nr 11, jesli LOW to
         delay(20);
         switch (i) {    // usrawia expandery registrowe nr 1,4,5,6,9 wg zapamietanej nastawy 
  case 0:
    // WK 1
    expander12.write(1); // zapala lampkę pod przyciskiem WK 1
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52) ;
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);
    break;
  case 1:
    // WK 2
    expander12.write(2);
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52);
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);
    break;
      case 2:
    // WK 3
    expander12.write(4);
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52);
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);
    break;
      case 3:
    // WK 4
    expander12.write(8);
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52);
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);    
    break;
      case 4:
    // WK 5
    expander12.write(16);
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52);
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);    
    break;
      case 5:
    // WK 6
    expander12.write(32);
b = expander1.read();
  expander1.write(nastawa_expander1[i]);
    operacjaNaBitach(b, nastawa_expander1[i], 36);
b = expander4.read();    
  expander4.write(nastawa_expander4[i]);
    operacjaNaBitach(b, nastawa_expander4[i], 44);
b = expander5.read();
 expander5.write(nastawa_expander5[i]);
  operacjaNaBitach(b, nastawa_expander5[i], 52);
b = expander8.read();
 expander8.write(nastawa_expander8[i]);
  operacjaNaBitach(b, nastawa_expander8[i], 60);
b = expander9.read();
  expander9.write(nastawa_expander9[i]);
    operacjaNaBitach(b, nastawa_expander9[i], 68);   
    break;
      case 6:
          // C - kasownik
          expander12.write(64);
expander1.write(0);
expander4.write(0);
expander5.write(0);
expander8.write(0);
expander9.write(0);
          noteSendAllNoteOff();
    break;  
      case 7:
      // CR - crescendo
        expander12.write(128);
    
        crescendo();
    
    break;

}
         
           delay(200);
           a = expander12.read();
           // Serial.println("stan WK na 11-12");
           // Serial.println(a);
           // Serial.println(b); 
           
}
  
}
}

// ****************** Procedura zmian i zapamietania ustawień dla WK ( programowanie WK) ************
// zapamiętanie ustawień WK ( SET )
void memory_WK(){
 // // Serial.println("wewnątrz funkcji memory");
 b = expander11.read();    
    
// set WK
  for (int i=0; i<8; i++){
      if (expander11.digitalRead(i) == LOW) { 
         delay(20);
         switch (i) {
  case 0:
    // odczyt i zapamiętanie nastawy dla WK 1
    expander12.write(1);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();
    break;
  case 1:
    // odczyt i zapamiętanie nastawy dla WK 2
    expander12.write(2);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();
    break;
      case 2:
    // odczyt i zapamiętanie nastawy dla WK 3
    expander12.write(4);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();
    break;
      case 3:
    // odczyt i zapamiętanie nastawy dla WK 4
    expander12.write(8);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();    
    break;
      case 4:
    // odczyt i zapamiętanie nastawy dla WK 5
    expander12.write(16);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();    
    break;
      case 5:
    // odczyt i zapamiętanie nastawy dla WK 6
    expander12.write(32);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();   
    break;
      case 6:
          // odczyt i zapamiętanie nastawy dla C 
          expander12.write(64);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();
    break;  
    case 7:
    // odczyt i zapamiętanie nastawy dla CR
    expander12.write(128);
nastawa_expander1[i] = expander1.read();
nastawa_expander4[i] = expander4.read();
nastawa_expander5[i] = expander5.read();
nastawa_expander8[i] = expander8.read();
nastawa_expander9[i] = expander9.read();   
    break;

}
          
           delay(200);
           a = expander12.read();
           // Serial.println("stan WK na 11-12");
           // Serial.println(a);
           // Serial.println(b); 
          // }
      }
 }
}  
void set_to_EPROM() {
    for (int i = 0; i < 6; i++){ // zapis nastaw dla do EPROM
      EEPROM.write(i + 10, nastawa_expander1[i]);
      EEPROM.write(i + 20, nastawa_expander4[i]);
      EEPROM.write(i + 30, nastawa_expander5[i]);
      EEPROM.write(i + 40, nastawa_expander8[i]);
      EEPROM.write(i + 50, nastawa_expander9[i]);
      EEPROM.write(i + 60, nastawa_expander9[i]);
   } 
   
    for (int i = 0; i < 5; i++){ // znak że zapisano - mryganie lampek
    expander12.write(255);
    delay(30);
    expander12.write(0); 
    delay(30); 
    delay(2000);
    }
}

void noteSend(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}  
void noteSendAllNoteOff() {
  Serial.write(0xB3);
  Serial.write(123);
  Serial.write(0);
} 
      
// fonkcja operacjaNaBitach porównuje nastawy przed wciśnienciem WK i po i wysyła odpowiednie komunikaty midi
void operacjaNaBitach(int przed, int po, int ofset){
        
   if (przed != po){
    
      for (int i = 0; i < 8; i++){
       if (bitRead(po,i) != bitRead(przed,i)){
        
           if bitRead(po,i){
              noteSend(cmdOn, i + ofset, 0x45);
            }
            else{
               noteSend(cmdOff, i + ofset, 0x00);
            }
        }
      }
    }
}

// **** Procedura obsługi crescendo *********
void crescendo(){ 
  // Serial.println("wejscie do procedury crescendo");
  int value;
  int c;
  while ( expander12.digitalRead(7) == HIGH ){
    
     if (digitalRead(11) == LOW) { 
      prog_crescendo();
     
     }
     
      if (digitalRead(10) == LOW){ // przycisk 9 włącza zapis nastawien do EPROM
      delay(10);
      cresc_to_EPROM(); 
      while (digitalRead(10) == LOW) {} // pusta petla zapobiega ponownemu wpisaniu do EPROM
      delay(10);
      }
      
      zmiana_WK();

     while (c == value) {
     c = value; 
     value = analogRead(A0); //Odczytujemy wartość napięcia na pinie A0
     delay(10);
     value = map(value, 0, 1000, 0, 19);//Przeskalowanie wartości
     //value = value / 51;
     zmiana_registrow(); 
     zmiana_WK();
     // return value; 
     }
     c = value;
     

b = expander1.read();
  expander1.write(cresc_expander1[value]);
    operacjaNaBitach(b, cresc_expander1[value], 36);
b = expander4.read();    
  expander4.write(cresc_expander4[value]);
    operacjaNaBitach(b, cresc_expander4[value], 44);
b = expander5.read();
 expander5.write(cresc_expander5[value]);
  operacjaNaBitach(b, cresc_expander5[value], 52);
b = expander8.read();
 expander8.write(cresc_expander8[value]);
  operacjaNaBitach(b, cresc_expander8[value], 60);
b = expander9.read();
  expander9.write(cresc_expander9[value]);
    operacjaNaBitach(b, cresc_expander9[value], 68);
     // Serial.println(value);
     delay(100);
    
  }
}

// **** Procedura programowania crescendo *********
void prog_crescendo(){ 
  expander12.write(128+64);

   for (int i=0; i<20; i++){
      
         delay(20);
         while (digitalRead(8) == HIGH) { 
          zmiana_registrow();
          }
         delay(500);
         
    // odczyt i zapamiętanie nastawy dla 20-stopniowego crescendo
    expander12.write(i+1+64+128);
cresc_expander1[i] = expander1.read();
cresc_expander4[i] = expander4.read();
cresc_expander5[i] = expander5.read();
cresc_expander8[i] = expander8.read();
cresc_expander9[i] = expander9.read();
          delay(500); 
   }   
expander12.write(0); 
delay(1000); 
expander12.write(128);  
}

// Zapis ustawień crescendo do EPROM
void cresc_to_EPROM() {
    for (int i = 0; i < 20; i++){ // zapis nastaw dla do EPROM
      EEPROM.write(i + 100, cresc_expander1[i]);
      EEPROM.write(i + 125, cresc_expander4[i]);
      EEPROM.write(i + 150, cresc_expander5[i]);
      EEPROM.write(i + 175, cresc_expander8[i]);
      EEPROM.write(i + 200, cresc_expander9[i]);
      
   } 
   
    for (int i = 0; i < 5; i++){ // znak że zapisano - mryganie lampek
    expander12.write(255);
    delay(200);
    expander12.write(0); 
    delay(200); 
    }
    delay(2000);
    
}
// while (digitalRead(7) == LOW) {} //Jeśli przycisk 7 jest wciśnięty program nic nie robi 
