#define LED1 13
int stanLED1 = LOW;
int channel_on = 0x90; // setup variable chcnell for man. I kanal 1
int  channel_off = 0x80; // /
unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzasLED1 = 0;
#define LiczbaKlawiszy (61)
boolean Key[LiczbaKlawiszy];
boolean Key2[LiczbaKlawiszy];
boolean Key3[LiczbaKlawiszy];
boolean Key4[LiczbaKlawiszy];

boolean Key_last[LiczbaKlawiszy];
boolean Key2_last[LiczbaKlawiszy];
boolean Key3_last[LiczbaKlawiszy];
boolean Key4_last[LiczbaKlawiszy];
int pin_data[] = {2,3,4,5,6,7,8,9};
int vol=90; 
void setup(){
  Serial.begin(115200);
  #define pin_adress0 A0
#define pin_adress1 A1
#define pin_adress2 A2
#define pin_E1_man1 A3
#define pin_E1_man2 A4
#define pin_E1_man3 A5
#define pin_E1_man4 10
  pinMode(LED1, OUTPUT);
    for (int i = 0; i <= LiczbaKlawiszy -1; i++) {
   Key[i] = 1;
   Key2[i] = 1;
   Key3[i] = 1;
   Key4[i] = 1;
   Key_last[i] = 1;
   Key2_last[i] = 1;
   Key3_last[i] = 1;
   Key4_last[i] = 1;
   }
     // define input pin_data
  for (int i = 0; i <= 7; i++) {
  pinMode(pin_data[i], INPUT_PULLUP);
  }
  //define output pin_adress 74HC138)
    pinMode(pin_adress0, OUTPUT);
 digitalWrite(pin_adress0, HIGH);
    pinMode(pin_adress1, OUTPUT);
 digitalWrite(pin_adress1, HIGH);
    pinMode(pin_adress2, OUTPUT);
 digitalWrite(pin_adress2, HIGH);

 //define output pin_E1 ( selest 74HC138) select manual
    pinMode( pin_E1_man1, OUTPUT);
 digitalWrite( pin_E1_man1, HIGH);
    pinMode( pin_E1_man2, OUTPUT);
 digitalWrite( pin_E1_man2, HIGH);
    pinMode( pin_E1_man3, OUTPUT);
 digitalWrite( pin_E1_man3, HIGH);
     pinMode( pin_E1_man4, OUTPUT);
 digitalWrite( pin_E1_man4, HIGH);
  pinMode( LED1, OUTPUT);
 
}
 
void loop(){
  //Pobierz liczbe milisekund od startu
  aktualnyCzas = millis();
  //aktualnyCzas = aktualnyCzas  + 1;
  
  //Jeśli różnica wynosi ponad 1 sekundę
  if (aktualnyCzas - zapamietanyCzasLED1 >= 500UL) {
    //Zapamietaj aktualny czas
    zapamietanyCzasLED1 = aktualnyCzas;
    //Zmieniamy stan diody na przeciwny
    stanLED1 = !stanLED1;
    //ustawiamy nowy stan na diodzie
    digitalWrite(LED1, stanLED1);
  }
  }
  
 
  
