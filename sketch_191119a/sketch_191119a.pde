import controlP5.*;
import processing.serial.*;
import websockets.*;

Serial port;
ControlP5 cp5;
Textfield mytextfield;
Textarea mytextarea1, mytextarea2;

WebsocketServer socket;

String mytext;
PFont font1;
PFont font2;
PImage img;

void setup()
{
  frame.setTitle("Morse code translator");
  
  //FUNKCJA SŁUŻĄCA DO WYPISANIA DOSTĘPNYCH PORTÓW
  //printArray(Serial.list());
  
  //DEKLARACJA ROZMIARU OKNA APLIKACJI
  size(500, 500);
 
  //USTAWIENIE ODPOWIEDNIEJ CZCIONKI
  font1 = createFont("calibri light",30);
  font2 = createFont("calibri light",25);
  
  //OPERACJE NA POPRZEDNIO STWORZONYCH OBIEKTACH
  port = new Serial(this, "COM8", 9600);
  cp5 = new ControlP5(this);
  socket = new WebsocketServer(this, 1337, "/p5websocket");
  
  //WYWOŁANIE ODPOWIEDNICH METOD DLA POLA TEKSTOWEGO, USTAWIENIE...
  mytextfield = cp5.addTextfield(" ") //..."NAZWY" OBIEKTU
                   .setPosition(50, 100) //...POZYCJI
                   .setSize(400, 50) //...ROZMIARU
                   .setAutoClear(true) //...AUTO CZYSZCZENIA
                   .setFont(font1); //...CZCIONKI
                   
  //STWORZENIE PRZYCISKU DO PRZESŁANIA WPISANEGO TEKSTU, USTAWIENIE JEGO...
                cp5.addBang("SEND") // ..."NAZWY"
                    .setPosition(350, 180)// ...POZYCJI
                    .setSize(100, 50)// ...ROZMIARU
                    .setFont(font2)// ...CZCIONKI
                    .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER);//...LOKALIZACJI NAZWY
  
  //STWORZENIE POLA TEKSTOWEGO NAD POLEM EDYCYJNYM, USTAWIENIE ...
     mytextarea1 =   cp5.addTextarea("text1") //..."NAZWY"
                    .setPosition(45,65) //...POZYCJI
                    .setSize(300,50) //...ROZMIARU
                    .setFont(createFont("arial",22)); //...CZCIONKI
                    
  //STWORZENIE STOPKI. USTAWIENIE..
      mytextarea2 =   cp5.addTextarea("text2") //..."NAZWY"
                    .setPosition(0,480) //...POZYCJI
                    .setSize(500,40) //...ROZMIARU
                    .setFont(createFont("arial",15)); //...CZCIONKI
                    
  //STWORZENIE PRZYCISKU MIKROFONU. UTWORZENIE..                  
                      cp5.addButton("Microphone")//..."NAZWY"
                    .setPosition(50,180)//...POZYCJI
                    .setImages(loadImage("../public/img/microphone.png"),loadImage("../public/img/microphone_r.png"),loadImage("../public/img/microphone_p.png"))//...GRAFIKI
                    .updateSize();//...DOSTOSOWANIE ROZMIARU
                   
}                   

void draw()
{
  //USTAWIENIE TŁA
  img = loadImage("../public/img/bg.png"); 
  background(img); 
  mytextarea1.setText("Enter text:");
  mytextarea2.setText("Universal morse code translator. Copyright: Ben Motyka");
}

//FUNKCJA ZWIĄZANA Z PRZYCISKIEM PRZESLIJ. PO WCISNIECIU PRZYCISKU...
void SEND() 
{
   //DO ZMIENNEJ mytext PRZYPISYWANE JEST TO, CO ZOSTAŁO WPISANE DO POLA mytextfield
   mytext = mytextfield.getText();
   
   //ZMIENNA mytext WYSYŁANA JEST PRZEZ PORT SZEREGOWY
   port.write(mytext);
}

//FUNKCJA DZIAŁAJĄCA GDY ZOSTANIE WCIŚNIĘTY PRZYCISK Z MIKROFONEM - TEKST MÓWIONY ZAMIENIANY JEST NA 
//TEKST W KOMPUTERZE I PRZYPISYWANY DO ZMIENNEJ msg 
void webSocketServerEvent(String msg)
 {
   mytext = msg;
   port.write(mytext);
 }
 
 //FUNKCJA POWODUJĄCA URUCHOMIENIE STRONY INTERNETOWEJ POZWALAJĄCEJ PRZECHWYTYWAĆ DŹWIĘK Z MIKROFONU
 void Microphone()
 {
  println("Launching page...");
  launch("../public/microphone.html");
 }
 
