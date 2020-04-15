#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
void keyboardRead();
int adc_value = 0x00;                       //armazena o valor digital do conversor AD

boolean right  = 0x00, butt01 = 0x00,
        up     = 0x00, butt02 = 0x00,
        down   = 0x00, butt03 = 0x00,
        left   = 0x00, butt04 = 0x00,
        select = 0x00, butt05 = 0x00;
        
        
// --- Hardware do LCD ---
LiquidCrystal disp(8,  //RS no digital 8
                   9,  //EN no digital 9
                   4,  //D4 no digital 4
                   5,  //D5 no digital 5
                   6,  //D6 no digital 6
                   7); //D7 no digital 7
        

char daysOfTheWeek[7][12] = {"DOM ", "SEG ", "TER ", "QUA ", "QUI ", "SEX!", "SAB"};
int hora_alarm = 6;
int minuto_alarm = 0;
int gatilho = 0;
int gatilho2 = 0;
void setup () {
 
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2018, 11, 15, 21, 20, 0));
  }

     
      disp.begin(16,2);      

}

void loop () {
   
    DateTime now = rtc.now();
    
    int ano = now.year();
    int mes = now.month();
    int dia = now.day();
    int hora = now.hour();
    int minutos = now.minute();
    int segundos = now.second();
                                  
     disp.setCursor(1,0);                                 
     disp.print(dia); 
     disp.print('/'); 
     disp.print(mes);  
     disp.print(" - ");
     disp.print(hora);
     disp.print(':'); 
     disp.print(minutos); 
     disp.print(':'); 
     disp.print(segundos);
   
    

  keyboardRead();
  
     if(select == 0x01){
      while(gatilho = 1){
      disp.setCursor(7,2);                         
      disp.print("--");
      delay(400);
      disp.setCursor(7,2); 
      disp.print(hora_alarm);
      delay(500);
      }
    
     if(hora_alarm < 0 || hora_alarm > 23){
      hora_alarm = 0;
     }
     
     if(up == 0x01){
        hora_alarm = hora_alarm + 1;   
      }
    } 
   Serial.print(hora_alarm);
   Serial.print(up);
   delay(1000);
    
   
    
  if(up == 0x01)                                 //tecla up pressionada?
    {                                              //sim...
      up = 0x00;                                   //limpa flag da tecla
      disp.setCursor(7,2);                         //Posiciona cursor na coluna 1, linha 2
      disp.print("  up            ");              //Imprime mensagem
    Serial.print("  up            "); 
    } //end if up
    
    if(down == 0x01)                               //tecla down pressionada?
    {                                              //sim...
      down = 0x00;                                 //limpa flag da tecla
      disp.setCursor(7,2);                         //Posiciona cursor na coluna 1, linha 2
      disp.print("  down          ");              //Imprime mensagem
    Serial.print("  down         "); 
    } //end if down
    
    if(left == 0x01)                               //tecla left pressionada?
    {                                              //sim...
      left = 0x00;                                 //limpa flag da tecla
      disp.setCursor(7,2);                         //Posiciona cursor na coluna 1, linha 2
      disp.print("  left          ");              //Imprime mensagem
    Serial.print("  left          "); 
    } //end if left
      
      }
 
 


void keyboardRead()
{
     adc_value = analogRead(A0);                       //Variável para leitura recebe valor AD de A0

     // --- Testa se os botões foram pressionados ---
     // Se foi pressionado, seta a respectiva flag
     if      (adc_value <  50)                    butt01 = 0x01;
     else if (adc_value > 103 && adc_value < 200) butt02 = 0x01;
     else if (adc_value > 250 && adc_value < 380) butt03 = 0x01;
     else if (adc_value > 450 && adc_value < 550) butt04 = 0x01;
     else if (adc_value > 700 && adc_value < 770) butt05 = 0x01;
    
     // --- Testa se os botões foram liberados ---
     //
     if (adc_value > 50 && butt01)             //Botão right solto e flag butt01 setada?
     {                                         //Sim...
         butt01 = 0x00;                        //Limpa flag butt01
         right  = 0x01;                        //Seta flag right
         
     } //end right
     if (adc_value > 200 && butt02)            //Botão up solto e flag butt02 setada?
     {                                         //Sim...
         butt02 = 0x00;                        //Limpa flag butt02
         up     = 0x01;                        //Seta flag up
      
     } //end up
     if (adc_value > 380 && butt03)            //Botão down solto e flag butt03 setada?
     {                                         //Sim...
         butt03 = 0x00;                        //Limpa flag butt03
         down   = 0x01;                        //Seta flag down
       
     } //end down
     if (adc_value > 550 && butt04)            //Botão left solto e flag butt04 setada?
     {                                         //Sim...
         butt04 = 0x00;                        //Limpa flag butt04
         left   = 0x01;                        //Seta flag left
       
     } //end left
     if (adc_value > 770 && butt05)             //Botão select solto e flag butt05 setada?
     {                                         //Sim...
         butt05 = 0x00;                        //Limpa flag butt05
         select  = 0x01;
     }
     } //end keyboardRead


     
      
