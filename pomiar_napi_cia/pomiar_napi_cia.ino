int odczytanaWartosc = 0;
 
void setup() {
  Serial.begin(9600);//Uruchomienie komunikacji przez USART
}
 
void loop() {
  odczytanaWartosc = digitalRead(7);//Odczytujemy wartość napięcia
  Serial.println(odczytanaWartosc);//Wysyłamy ją do terminala
  delay(200);//Czekamy, aby wygodniej odczytywać wyniki  
}
