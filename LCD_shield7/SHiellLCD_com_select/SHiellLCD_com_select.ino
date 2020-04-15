#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Define Pinos do Display
 
int Menu = 0; // Inicializa valores para Menu
int estado = 0; // Inicializa valores para estado
 int a_h = 6;
 int a_m = 0;
void setup() {
 lcd.begin(16, 2); // Estabelece caracteres do display
 clearPrintTitle();
 Serial.begin(9600);
}
 
void loop() {
 MenuPrincipal();
 Serial.print(a_h);
Serial.print("-");
Serial.println(a_m);
delay(5);
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
 
 if (Menu < 0 || Menu > 26) {
 Menu = 0; 
 }
 
 if (ValEstado != estado) {
 if (ValEstado == 1) {
 Menu = Menu - 1; 
 displayMenu(Menu);
 } else if (ValEstado == 2) {
 Menu = Menu + 1; 
 displayMenu(Menu);
 } else if (ValEstado == 3) {
 selectMenu(Menu); 
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
 lcd.print(" UsinaInfo ");
 lcd.setCursor(0,1); 
}
 
void selectMenu(int x) {
 switch (x) {
 case 4:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 5:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 6:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 7:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 8:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 9:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 10:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 11:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 12:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 13:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 14:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 15:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 16:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 17:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 18:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 19:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 20:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 21:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 22:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 23:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 24:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 25:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 26:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 27:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 case 28:
 clearPrintTitle();
 lcd.print ("Alarme Salvo"); // Imprime na tela opção escolhida
 break;
 }
}
