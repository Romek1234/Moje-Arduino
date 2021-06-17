#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza
 
void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  lcd.clear();
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Nap. odczytane");
  lcd.setCursor(0,1);
  lcd.print("0.00V"); 
}
 
double odczyt;
 
void loop()
{
  odczyt = analogRead(A0)*5.0/1024.0; //Wartość napięcia
  lcd.setCursor(0, 1); //Ustawienie kursora w odpowiednim momencie
  lcd.print(odczyt); //Wyświetlenie tekstu
  delay(250); //Opóźnienie
}
