//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Carlyn Maw,Tom Igoe                               //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

String odebraneDane = ""; //Pusty ciąg odebranych danych
unsigned long j = 0;
unsigned long k = 0;

void setup() {
  Serial.begin(9600);
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
//   if(Serial.available() > 0) { //Czy Arduino odebrało dane
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
//    odebraneDane = Serial.readStringUntil('\n'); 
    
 //   if (odebraneDane == "zapal2na1") { //Jeśli odebrano słowo "zielona"
 //     bitSet(j, 1);
 //   zapiszdo595(j, k);
 //   }
 //   if (odebraneDane == "zgas2na1") { //Jeśli odebrano słowo "czerwona"
//        bitClear(j, 1);
//    zapiszdo595(j, k); 
 //   }
 //    if (odebraneDane == "zapal3na1") { //Jeśli odebrano słowo "zielona"
//      bitSet(j, 2);
//    zapiszdo595(j, k);
 //   }
 //if (odebraneDane == "zgas3na1") { //Jeśli odebrano słowo "czerwona"
 //       bitClear(j, 2);
  //  zapiszdo595(j, k); 
  //  }
  // }
  // Do this for MSBFIRST serial
// int data = 500;
// shift out highbyte
//shiftOut(dataPin, clockPin, MSBFIRST, (data >> 8));
// shift out lowbyte
//shiftOut(dataPin, clockPin, MSBFIRST, data);

// Or do this for LSBFIRST serial
//data = 500;
// shift out lowbyte
//shiftOut(dataPin, clockPin, LSBFIRST, data);
// shift out highbyte
//shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));
  //count up routine
 //for (int i = 0; i < 8; i++) { 
   //  Serial.print(i, HEX);

   //  Serial.print(" ");
 /// bitSet(j, i);
 // zapiszdo595 (j,k);
 // delay (30);
 //// bitClear(j, i);
  //zapiszdo595 (j,k);
  //delay (30);

//delay ();
 //}

 for (int i = 36; i < 101; i++) { 
     Serial.print(i, HEX);

     Serial.print(" ");
  if (i > 35 and i < 69) {
        bitSet(j, i - 36);
        zapiszdo595(j, k);
    }
         if (i > 68 and i < 101) {
        bitSet(k, i - 72);
        zapiszdo595(j, k);
    }
 }
 //delay(1000);   
     for (int i = 36; i < 101; i++) { 
     Serial.print(i, HEX);

     Serial.print(" ");
  if (i > 35 and i < 69) {
        bitClear(j, i - 36);
        zapiszdo595(j, k);
    }
         if (i > 68 and i < 101) {
        bitClear(k, i - 72);
        zapiszdo595(j, k);
    }

//delay ();
 }
 //delay(1000); 


  
}
void zapiszdo595(unsigned long p,unsigned long q) {
 
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 24));
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 16));
shiftOut(dataPin, clockPin, MSBFIRST, (q >> 8));
shiftOut(dataPin, clockPin, MSBFIRST, q);
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 24));
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 16));
shiftOut(dataPin, clockPin, MSBFIRST, (p >> 8));
shiftOut(dataPin, clockPin, MSBFIRST, p);

digitalWrite(latchPin, HIGH);  
}
