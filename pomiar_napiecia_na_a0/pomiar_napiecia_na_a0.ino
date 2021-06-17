
int odczytanaWartosc = 0;//Odczytana wartość z ADC
int napiecie = 0;//Wartość przeliczona na napięcie w V
int mem =0; 
void setup() {
  Serial.begin(9600);//Uruchomienie komunikacji przez USART
}
 
void loop() {
  mem = napiecie;
  odczytanaWartosc = analogRead(A5);//Odczytujemy wartość napięcia
  napiecie = odczytanaWartosc / 51; //Przeliczenie wartości na napięcie
  if (napiecie != mem) Serial.println(napiecie);//Wysyłamy zmierzone napięcie
  
  delay(200);//Czekamy, aby wygodniej odczytywać wyniki  
}
