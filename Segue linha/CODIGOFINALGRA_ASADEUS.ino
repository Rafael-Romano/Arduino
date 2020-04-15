    int velMax = 220;
  float velE = velMax;
  float velD = velMax;
  int s1 = 0;
  int s2 = 0;
  int s3 = 0;
  int s4 = 0;
  int s5 = 0;  
  int sD = 0;
  int sE = 0;
  int parar = 0;
  float tempoA = 0;
  float tempo = 0;
  int gatilho = 0;
  float tempoAS = 0;
  float tempoS = 0;
  float tempoAC = 0;
  float tempoC = 0;
  int sensornaFx = 0;   
  float KD = 18; 
  float KP = 1.7;
  float K = 14;
  float KE = 2.38;
  int curva = 0;
  int parada = 0;
  int cruzamento = 0;
  
  #define motorD 6
  #define motorE 5
  #define sensorD 10
  #define sensorE 11
  #define sensor1 A1
  #define sensor2 A2
  #define sensor3 A3
  #define sensor4 A4
  #define sensor5 A5
 
  
  
void setup() {
pinMode(motorE,OUTPUT);
pinMode(motorD,OUTPUT);
pinMode(sensorD,INPUT);
pinMode(sensorE,INPUT);

Serial.begin(9600);
}

void loop() {

  s1 = analogRead(sensor1);
  s2 = analogRead(sensor2);
  s3 = analogRead(sensor3);
  s4 = analogRead(sensor4);
  s5 = analogRead(sensor5);
  sD = digitalRead(sensorD);
  sE = digitalRead(sensorE);
  
  
/// Millis funfando      
if(s3 < 500){
  tempoA = millis();
  tempo = 0;
 
  }
if(s3 > 500){
tempo = ((millis() - tempoA)/745);
}
if (sD == 1 && cruzamento == 0) //
{
tempoAC = millis();
if (curva == 0){parada = 1;}
if (curva == 1){curva=0; cruzamento=1;}
}

tempoC = millis()-tempoAC; 

if(sE == 1){ 
if(curva == 1 && cruzamento == 0)
{
curva = 0;
}
tempoAC = millis();
if (parada == 0){parada = 0;cruzamento = 1;}
if (parada == 0){curva=1;}
}

if(curva == 1 && cruzamento == 0)
{
// APLICA A CURVA AQUI
 KD = 18; 
   KP = 2.8;
   K = 15;
   KE = 2.38;
   velMax = 100;
}
if(curva == 0)
{
 KD = 18; 
   KP = 1.7;
   K = 13;
   KE = 1.20;
   velMax = 160;
   
  }
if(parada == 1 && cruzamento == 0 && tempoC > 500)
{
parar = 1;
}
if (tempoC > 80)
{
  cruzamento = 0;
  }


  ///Identificar qual sensor está ligado
  if(s1 < 500){
  sensornaFx = 6; 
  }
  if(s2 < 500){
  sensornaFx = 8;
  }
  if(s3 < 500){
  sensornaFx = 10;
  }
  if(s4 < 500){
  sensornaFx = 12;
  }
  if(s5 < 500){
  sensornaFx = 14;
  }

//if (curva == 1){ 
//   KD = 18; 
//   KP = 1.7;
//   K = 14;
//   KE = 2.38;
//   velMax = 150;
//  }
//if (curva == 0){ 
//  KD = 18; 
//   KP = 1.7;
//   K = 14;
//   KE = 2.38;
//   velMax = 240;
//   }



  // CÁLCULO PD
  int erro = sensornaFx - 10;
  int ajuste = KP * (tempo) + KD * erro;
    erro = (KD * erro) * KE;      
      float novavelD = velD - (K * ajuste);
      float novavelE = velE + (K * ajuste);
if (novavelD < 0){
    novavelD = 0;}
  if (novavelE < 0){ 
    novavelE = 0;}
  if (novavelD > velMax){
    novavelD = velMax;}
  if (novavelE > velMax){
    novavelE = velMax;}  
    if (parar == 0)
    { 
  analogWrite(motorE,novavelE);
  analogWrite(motorD,novavelD);
    }  if (parar == 1)
    { 
  analogWrite(motorE,0);
  analogWrite(motorD,0);
    }
  Serial.print(curva);
    Serial.print("||");
      Serial.print(cruzamento);
        Serial.print("||");
          Serial.print(velMax);        Serial.println();
    


}

  
 
