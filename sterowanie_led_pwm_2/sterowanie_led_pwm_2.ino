 
int led = 5;   // the pin that the LED is attached to Arduino
int odczytanaWartosc = 0;
int brightness = 0;
//int fadeAmount = 5;  // how many points to fade the LED by
  
void setup() {
  
// declare pin 5 to be an output:
  pinMode(led, OUTPUT);
}

void loop() {
  odczytanaWartosc = analogRead(A5);//Odczytujemy wartość napięcia
   brightness = odczytanaWartosc * (255.0/1024.0);
   analogWrite(led, brightness);

  // wait for 50 milliseconds to see the dimming effect
  //delay(50);
}
