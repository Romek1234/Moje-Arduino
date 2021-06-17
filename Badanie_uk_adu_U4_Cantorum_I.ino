/*
  Badanie ukladu U4 Cantorum I

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/


byte LED = 0;
int x = 0;
int y = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
    pinMode(12, OUTPUT);
      pinMode(11, OUTPUT);
        pinMode(10, OUTPUT);
          pinMode(9, OUTPUT);
            pinMode(8, OUTPUT); 
              pinMode(7, OUTPUT);
                pinMode(6, OUTPUT);
                  pinMode(5, OUTPUT);
pinMode(A0, INPUT_PULLUP);
pinMode(A1, INPUT_PULLUP);
pinMode(A2, INPUT_PULLUP);
pinMode(A3, INPUT_PULLUP);
pinMode(A4, INPUT_PULLUP);
pinMode(A5, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);

                  
//Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // prints title with ending line break
  Serial.println("BEGIN PROGRAM  ");


// first visible ASCIIcharacter '!' is number 33:
int thisByte = 33;
// you can also write ASCII characters in single quotes.
// for example, '!' is the same as 33, so you could also use this:
// int thisByte = '!';
                
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(5, LOW);
  Serial.println("pin Input10 - LOW");
  for ( x=0; x<256; x++){
    Serial.print(x, HEX);
    Serial.print(' ');
 
    Serial.print(x, BIN);
    
    Serial.print(' ');
  for (LED=0; LED < 8; LED++)
  {
     
  digitalWrite(LED+6, bitRead(x,LED));   // turn the LED on (HIGH is the voltage level)
                      // wait for a second
   
  }// wait for a second
    delay(100); 
  
  y=0;
  if (digitalRead(A0)==HIGH) {
    bitSet(y, 0);
  }
   if (digitalRead(A1)==HIGH) {
    bitSet(y, 1);
  }
 
   if (digitalRead(A2)==HIGH) {
    bitSet(y, 2);
  }
   if (digitalRead(A3)==HIGH) {
    bitSet(y, 3);
  }
   if (digitalRead(A4)==HIGH) {
    bitSet(y, 4);
  }
   if (digitalRead(A5)==HIGH) {
    bitSet(y, 5);
  }
 
   if (digitalRead(2)==HIGH) {
    bitSet(y, 6);
  }
    if (digitalRead(3)==HIGH) {
    bitSet(y, 7);
  }

 Serial.println(y, BIN); 

 delay(10); 
}


digitalWrite(5, HIGH);
Serial.println("pin Input10 - HIGH");
  for ( x=0; x<256; x++){
    Serial.print(x, HEX);
    Serial.print(' ');
    
    Serial.print(x, BIN);
    
    Serial.print(' ');
  for (LED=0; LED < 8; LED++)
  {
     
  digitalWrite(LED+6, bitRead(x,LED));   // turn the LED on (HIGH is the voltage level)
                      // wait for a second
   
  }// wait for a second
    delay(100); 
  
  y=0;
  if (digitalRead(A0)==HIGH) {
    bitSet(y, 0);
  }
   if (digitalRead(A1)==HIGH) {
    bitSet(y, 1);
  }
 
   if (digitalRead(A2)==HIGH) {
    bitSet(y, 2);
  }
   if (digitalRead(A3)==HIGH) {
    bitSet(y, 3);
  }
   if (digitalRead(A4)==HIGH) {
    bitSet(y, 4);
  }
   if (digitalRead(A5)==HIGH) {
    bitSet(y, 5);
  }
 
   if (digitalRead(2)==HIGH) {
    bitSet(y, 6);
  }
    if (digitalRead(3)==HIGH) {
    bitSet(y, 7);
  }
 
 Serial.println(y, BIN); 

 delay(10); 
}
Serial.println(" END PROGRAM "); 
 delay(2000); 

}
