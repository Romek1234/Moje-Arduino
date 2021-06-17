void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //Ustawienie prędkości transmisji
}

void loop() {
  for( int i=0; i<=1023; i++ )
  {
    Serial.print(i);
    Serial.print("\t");
    Serial.println(map(i, 0, 1000, 0, 19)); // Check the limits there
  }
delay(20000);
}
