#include <RTClib.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define pin1 2
#define pin2 3

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"DOM ", "SEG ", "TER ", "QUA ", "QUI ", "SEX!", "SAB"};

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Define Pinos do Display
 
int Menu = 0; // Inicializa valores para Menu
int estado = 0; // Inicializa valores para estado
 int a_h = 6;
 int a_m = 0;


void setup() {

 pinMode(pin1, OUTPUT);
 pinMode(pin2, OUTPUT);
 digitalWrite( pin1, HIGH);
 digitalWrite( pin2, HIGH);
 
 lcd.begin(16, 2); // Estabelece caracteres do display
 clearPrintTitle();
   while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
   rtc.adjust(DateTime(2018, 11, 15, 6, 19, 0));
}
 
void loop() {
 MenuPrincipal();
delay(5);
 DateTime now = rtc.now();
    
    int ano = now.year();
    int mes = now.month();
    int dia = now.day();
    int hora = now.hour();
    int minutos = now.minute();
    int segundos = now.second();
                                  
     lcd.setCursor(1,0);                                 
     lcd.print(dia); 
     lcd.print('/'); 
     lcd.print(mes);  
     lcd.print(" - ");
     lcd.print(hora);
     lcd.print(':'); 
     lcd.print(minutos); 
     lcd.print(':'); 
     lcd.print(segundos);
       
  if(hora == a_h && minutos == a_m){
  digitalWrite( pin1, LOW);
  delay(20000);
  digitalWrite( pin2, LOW);
  delay(10000);
 }
else{
  digitalWrite( pin1, HIGH);
  digitalWrite( pin2, HIGH);
}
}
 
void MenuPrincipal() {
 int ValEstado = 0; // Inicializa valores para ValEstado
 int x = analogRead (0);
 lcd.setCursor(0,0); // Posiciona Cursor
 
 if (x < 80) { // Define valores máximos para UP em ValEstado = 1
 } 
 else if (x < 200) {
 ValEstado = 1;
 } 
 else if (x < 400){ // Define valores máximos para Down em ValEstado = 2
 ValEstado = 2;
 }
 else if (x < 600){ // Define ação nula para Left
 } 
 else if (x < 800){ // Define valores máximos para Select em ValEstado = 3
 ValEstado = 3;
 }
 
 if (Menu < 4 || Menu > 27) {
 Menu = 4; 
 }
 
 if (ValEstado != estado) {
 if (ValEstado == 1) {
 Menu = Menu - 1; 
 displayMenu(Menu);
 } else if (ValEstado == 2) {
 Menu = Menu + 1; 
 displayMenu(Menu);
 } else if (ValEstado == 3) {

 }
 estado = ValEstado;
 } 
 delay(5);
}
 
void displayMenu(int x) {
 switch (x) {
 case 4:
 a_m = 0;
 a_h = 6;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 5:
 a_m = 10;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 6:
 a_m = 20;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 7:
 a_m = 30;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 8:
 a_m = 40;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 9:
 a_m = 50;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 10:
 a_m = 0;
 a_h = 7;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 11:
 a_m = 10;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 12:
 a_m = 20;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 13:
 a_m = 30;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 14:
 a_m = 40;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 15:
 a_m = 50;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 16:
 a_m = 0;
 a_h = 8;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 17:
 a_m = 10;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 18:
 a_m = 20;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 19:
 a_m = 30;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 20:
 a_m = 40;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 21:
 a_m = 50;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 22:
 a_m = 0;
 a_h = 9;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 23:
  a_m = 10;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 24:
  a_m = 20;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 25:
  a_m = 30;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 26:
  a_m = 40;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 27:
  a_m = 50;
 clearPrintTitle();
 lcd.setCursor(6,2);
 lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 break;
 case 28:
  a_m = 0;
  a_h = 10;
  lcd.print (a_h);
  lcd.print (':');
   lcd.print (a_m);
 
 break;
 }
}
 
void clearPrintTitle() {
 lcd.clear();
 lcd.setCursor(0,0);
 
}
 
