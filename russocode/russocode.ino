#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  //Zadaet razmer jekrana
  lcd.begin(16, 2);
  //Ochistka jekrana
  lcd.clear();
  //Regylirovka podsvetky jekrana
  analogWrite(10, 30);
}

byte key() {
  //1-640 SELECT, 2-411 LEFT, 3-101 UP, 4-256 DOWN, 5-0 RIGHT soprotivlenie knopok
  int val = analogRead(0);
  //Zadaem nomer knopki
  if (val < 50) return 5;
  else if (val < 150) return 3;
  else if (val < 350) return 4;
  else if (val < 500) return 2;
  else if (val < 800) return 1;
  else if (val <= 1023) return 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Otchistit jekran
  lcd.clear();
  //Ystanovka kyrsora: nylevoi simvol, nylevay stroka
  lcd.setCursor(0, 0);
  // Napisati slovo "analogRead"
  lcd.print("analogRead");
  //Yznaem kakoe soprotivlenie na knopkah
  //Vozvrashhaet funkciju analoRead v nylevom kontakte
  lcd.print(analogRead(0));
  //Kyrsor na vtoryu stroky
  lcd.setCursor(0, 1);
  //Kakaya knopka nazata ispolzyem operator "switch"
  switch (key()) {
    case 1:
      //Esli "key" nam vernyl 1, pokazivaem na jekrane "select"
      lcd.print("Select");
      //Ne vihodim iz operatora
      break;
    case 2:
      lcd.print("Left");
      break;
    case 3:
      lcd.print("Up");
      break;
    case 4:
      lcd.print("Down");
      break;
    case 5:
      lcd.print("Rigth");
  }
 
  delay(250);
}﻿
