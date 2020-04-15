#define    umidade_ideal  700
#define    analogi    A0
#define    digital    15
#define    gnd_pin    16
#define    vcc_pin    17
#define    rele_pin   5

void ler_humidade(int var);
int leitura = 0x00;

void setup()
{
    Serial.begin(115200);
    
    pinMode(analogi,  INPUT);
    pinMode(digital,  INPUT);
    pinMode(gnd_pin, OUTPUT);
    pinMode(vcc_pin, OUTPUT);
    pinMode(rele_pin, OUTPUT);

    digitalWrite(gnd_pin,  LOW);
    digitalWrite(vcc_pin, HIGH);
    digitalWrite(rele_pin, LOW);
}

void loop()
{
  ler_umidade(umidade_ideal);                             
  delay(741);                                                    
}

void ler_umidade(int var)
{
  leitura = analogRead(analogi);                                                                   
  Serial.println(leitura);                                         
 
  if (leitura > 0 && leitura < var)             
    {
    digitalWrite(rele_pin, HIGH);  
    }

  else if (leitura > var && leitura < 1024)     
    {
      digitalWrite(rele_pin, LOW);
    }  
} 
 
 
