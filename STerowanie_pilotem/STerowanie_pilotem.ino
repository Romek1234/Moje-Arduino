#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
 
void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
      switch (results.value) {
         case 0x143226DB:
            Serial.println("w lewo");
            break;
 
         case 0xE0984BB6:
            Serial.println("w doł");
            break;
 
         case 0x39D41DC6:
            Serial.println("w prawo");
            break;
 
         case 0x6170D02F:
            Serial.println("w gorę");
            break;
 
         case 0x6170A857:
            Serial.println("srodek");
            break;
         }
 
   irrecv.resume();
   }
}
