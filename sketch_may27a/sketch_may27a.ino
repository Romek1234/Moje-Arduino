int odebraneDane = 0; //Pusty ciąg odebranych danych
 
void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
}
 
void loop() {
  if(Serial.available() > 0) { //Czy Arduino odebrało dane
    odebraneDane = Serial.read(); //Jeśli tak, to odczytaj je do znaku końca linii i zapisz w zmiennej odebraneDane
    Serial.println(odebraneDane); //Wyświetl komunikat
  }
}
