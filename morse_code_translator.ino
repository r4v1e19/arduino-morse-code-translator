#include <LiquidCrystal.h>

int diode = 8;
int buzzer = 9;
int i; 
String text;

//USTAWIENIE ODPOWIEDNICH PINÓW DLA WYSWIETLACZA LCD 
LiquidCrystal lcd(12,11,5,4,3,2);

//DEKLARACJA FUNKCJI.
char check(char); //FUNKCJA SPRAWDZAJĄCA DANY ZNAK 
void ss(); //FUNKCJA SIGNAL SHORT, SPRAWIA, ŻE DIODA I BUZZER EMITUJĄ KRÓTKI SYGNAŁ
void sl(); //FUNKCA SIGNAL LONG, SPRAWIA, ŻE DIODA I BUZZER EMITUJĄ DŁUŻSZY SYGNAŁ

void setup() {
  pinMode(diode, OUTPUT); //USTAWIENIE, ŻE PIN 8 BĘDZIE WYJSCIEM...
  pinMode(buzzer, OUTPUT); //...I PIN 9 TEZ WYJSCIEM
  lcd.begin(16,2); //USTAWIENIE KURSORA NA WYSWIETLACZU LCD
  Serial.begin(9600); //OTWORZENIE PORTU SZEREGOWEGO,
  //USTAWIENIE PRĘDKOSCI TRANSMISJI DANYCH NA 9600 BITOW NA SEKUNDE
}

void loop() 
{
  //SPRAWDZENIE CZY PORT SZEREGOWY JEST DOSTEPNY...
  if(Serial.available()>0)
  {
    //..JESLI TAK, TO DO ZMIENNEJ text PRZYPISUJE TO, CO PRZYSZŁO Z PORTU SZEREGOWEGO
    String text = Serial.readString();
    //FUNKCJA KTORA ZAMIENIA CIAG ZNAKOW NA TAKI, W KTORYM WYSTEPUJA TYLKO MALE LITERY.
    text.toLowerCase();
    //ZRESETOWANIE ZMIENNEJ KTORA UZYWANA JEST W PETLI
    i = 0;
    //PETLA SPRAWDZAJACA KAZDY ZNAK W SLOWIE
    lcd.print(text); //WYGENEROWANIE TEKSTU NA WYSWIETLACZU LCD
    for (i; i < text.length(); i++)
    {
      check(text[i]);
      delay(500);
    }
  }
}

void sl()
{
  digitalWrite(diode, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(diode, LOW);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void ss()
{
  digitalWrite(diode, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(diode, LOW);
  digitalWrite(buzzer, LOW);
  delay(100);
}

char check(char text)
{
  if (text == 'a') {
    ss();
    sl();
  }
  if (text == 'b') {
    sl();
    ss();
    ss();
    ss();
  }
  if (text == 'c') {
    sl();
    ss();
    sl();
    ss();
  }
  if (text == 'd') {
    sl();
    ss();
    ss();
  }
  if (text == 'e') {
    ss();
  }
  if (text == 'f') {
    ss();
    ss();
    sl();
    ss();
  }
  if (text == 'g') {
    sl();
    sl();
    ss();
  }
  if (text == 'h') {
    ss();
    ss();
    ss();
    ss();
  }
  if (text == 'i') {
    ss();
    ss();
  }
  if (text == 'j') {
    ss();
    sl();
    sl();
    sl();
  }
  if (text == 'k') {
    sl();
    ss();
    sl();
  }
  if (text == 'l') {
    ss();
    sl();
    ss();
    ss();
  }
  if (text == 'm') {
    sl();
    sl();
  }
  if (text == 'n') {
    sl();
    ss();
  }
  if (text == 'o') {
    sl();
    sl();
    sl();
  }
  if (text == 'p') {
    ss();
    sl();
    sl();
    ss();
  }
  if (text == 'r') {
    ss();
    sl();
    ss();
  }
  if (text == 's') {
    ss();
    ss();
    ss();
  }
  if (text == 't') {
    sl();
  }
  if (text == 'u') {
    ss();
    ss();
    sl();
  }
  if (text == 'v') {
    ss();
    ss();
    ss();
    sl();
  }
  if (text == 'w') {
    ss();
    sl();
    sl();
  }
  if (text == 'x') {
    sl();
    ss();
    ss();
    sl();
  }
  if (text == 'y') {
    sl();
    ss();
    sl();
    sl();
  }
  if (text == 'z') {
    sl();
    sl();
    ss();
    ss();
  }
  if (text == '1') {
    ss();
    sl();
    sl();
    sl();
    sl();
  }
  if (text == '2') {
    ss();
    ss();
    sl();
    sl();
    sl();
  }
  if (text == '3') {
    ss();
    ss();
    ss();
    sl();
    sl();
  }
  if (text == '4') {
    ss();
    ss();
    ss();
    ss();
    sl();
  }
  if (text == '5') {
    ss();
    ss();
    ss();
    ss();
    ss();
  }
  if (text == '6') {
    sl();
    ss();
    ss();
    ss();
    ss();
  }
  if (text == '7') {
    sl();
    sl();
    ss();
    ss();
    ss();
  }
  if (text == '8') {
    sl();
    sl();
    sl();
    ss();
    ss();
  }
  if (text == '9') {
    sl();
    sl();
    sl();
    sl();
    ss();
  }
  if (text == '0') {
    sl();
    sl();
    sl();
    sl();
    sl();
  }
}
