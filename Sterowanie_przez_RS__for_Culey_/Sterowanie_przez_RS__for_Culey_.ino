//#include <SoftwareSerial.h>
#define zielona 8
#define czerwona 13
//SoftwareSerial mySerial(10, 11); // RX, TX
int odebraneDane = 0; //Pusty ciąg odebranych danych
 
void setup() {
  Serial.begin(1200); //Uruchomienie komunikacji

 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
   }
   Serial.println("Goodnight moon!");
  pinMode(zielona, OUTPUT); //Konfiguracja wyjść
  pinMode(czerwona, OUTPUT);
   digitalWrite(zielona, LOW); //Wyłączamy diody
  digitalWrite(czerwona, LOW);
  // set the data rate for the SoftwareSerial port
//  mySerial.begin(1200);
//  mySerial.println("Hello, world?1");
} 
void loop() {
  if(Serial.available() > 0) { //Czy Arduino odebrało dane
    odebraneDane = Serial.read(); //Jeśli tak, to odczytaj je do znaku końca linii i zapisz w zmiennej odebraneDane
    Serial.println(odebraneDane); //Wyświetl komunikat

   if (odebraneDane == 170) { //Jeśli odebrano słowo "czerwona"
      digitalWrite(czerwona, HIGH); //To włączamy diodę czerwoną
      delay(2000);
      digitalWrite(czerwona, LOW); 
    }
  

 
 
}
}  
