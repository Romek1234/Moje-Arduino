// 
int led = 5;   // Pin który stereruje paskiem LED
int fan = 6;   // Pin który stereruje wentylatem

int button = 7;  // Pin który reaguje na przycisniecie gałki regulatora
int buzzer = 8; //Pin który stereruje buzerem (sygnał)
                //A2 - pin analogowy na którym kontrolujemy napięcie aku
                //A5 - pin analogowy do którego podączamy środek potenciometru do regul.
const float min_Napiecie_aku = 11.3;  // minimalne napięcie aku - poniżej wyłącza                            
int odczytanaWartosc = 0;
int odczytanaWartosc_U_aku = 0;
float Napiecie_aku = 0; // zmierzone napięcie akumulatora
int brightness = 0; 
boolean StanButton = 0;
//int fadeAmount = 5;  // how many points to fade the LED by

  float fmap(float x, float in_min, float in_max, float out_min, float out_max){
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
void setup() {
  
// declare pin 5 to be an output:
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
   Serial.begin( 9600 );
}

void loop() {
  
    odczytanaWartosc_U_aku = analogRead(A2);//Odczytujemy wartość napięcia na dzielniku 4 do 1 czyli np.15kohm i 5 kohm
    Napiecie_aku = fmap(odczytanaWartosc_U_aku, 0, 1023, 0.0, 31.5); //Obliczmy wartoć 
    Serial.print( "Readout: " );
  Serial.println( odczytanaWartosc_U_aku );
  Serial.print( "Voltage: " );
  Serial.println( Napiecie_aku, 4 );
  
    if (Napiecie_aku <= min_Napiecie_aku) {
    proceduraOFF();
    }
  if (digitalRead(button) == StanButton) {
        odczytanaWartosc = analogRead(A5);//Odczytujemy wartość napięcia na potenciometrze i przeliczamy na wartosc od 0 do 255
        brightness = odczytanaWartosc * (255.0/1024.0);
            if (StanButton == HIGH) {
               analogWrite(led, brightness);
            }
            else {
               analogWrite(fan, brightness);
            }
  } 
   else { 
       StanButton = digitalRead(button);
       delay(50); // wait for 50 milliseconds to see the dimming effect
  
   }
   
  
}
 
void proceduraOFF()
{
  Serial.print( "  Rozpoczęta procedura wyłączania - niskie napięcie:  " );
   Serial.println(Napiecie_aku,2 );
   delay(1000);
   kratki();
//  buzzON();
 delay(1000);
 odczytanaWartosc_U_aku = analogRead(A2);//Odczytujemy wartość napięcia na dzielniku 4 do 1 czyli np.15kohm i 5 kohm
 Napiecie_aku = fmap(odczytanaWartosc_U_aku, 0, 1023, 0.0, 31.5); //Obliczmy wartoć 

    if (Napiecie_aku <= min_Napiecie_aku) {
       Serial.print( "    Procedura wyłączania trwa - nadal niskie napięcie:  ");
       Serial.println(Napiecie_aku,2 );
        kratki();
       delay(2000);
       Serial.println( "  Wyłączam wentylator !!!");
        kratki();
        delay(2000);
       analogWrite(fan, 0);
       Serial.println( "  Wysyłam błysk ostrzegawczy !!!");
        
       for (int i = 255; i >= 0; i--){
       analogWrite(led, i);
       delay(20);
       }
       delay(2000);
        Serial.println( "  Jeszcze raz sprawdzam napięcie !!!");
        kratki();
        odczytanaWartosc_U_aku = analogRead(A2);//Odczytujemy wartość napięcia na dzielniku 4 do 1 czyli np.15kohm i 5 kohm
        Napiecie_aku = fmap(odczytanaWartosc_U_aku, 0, 1023, 0.0, 31.5); //Obliczmy wartoć 
       Serial.print( "  Napięcie akumulatora wynosi:  ");
       Serial.print(Napiecie_aku,2 );
       Serial.println( "  To niestety za mało !!!  ");
       kratki();
       Serial.println( "  Przechodzę do stanu czuwania  ");
       
         while (Napiecie_aku < (min_Napiecie_aku + 0.2)) {
         delay(1000);
         Serial.print( " $ ");
         Serial.print(Napiecie_aku,2 );
         odczytanaWartosc_U_aku = analogRead(A2);//Odczytujemy wartość napięcia na dzielniku 4 do 1 czyli np.15kohm i 5 kohm
         Napiecie_aku = fmap(odczytanaWartosc_U_aku, 0, 1023, 0.0, 31.5); //Obliczmy wartoć 

         }
    }
}
void buzzON()
{
  for (int t =255; t = 0; t--){
  digitalWrite(buzzer, HIGH);
  delay(10);
  digitalWrite(buzzer, LOW);
  delay(10);
  }
}
void kratki()
{
  for(int i=0; i<=5; i++){
  Serial.print( " #");
  delay(1000);
  }
    Serial.println( " #");
  }
