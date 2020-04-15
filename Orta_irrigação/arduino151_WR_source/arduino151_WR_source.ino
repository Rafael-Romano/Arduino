/* ========================================================================================================
 
   Curso de Arduino e AVR 151
   
   WR Kits Channel


   Sensor de Umidade de Solo com Arduino

    
   Autor: Eng. Wagner Rambo  Data: Dezembro de 2017
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits


   Software baseado no artigo:
   https://www.filipeflop.com/blog/monitore-sua-planta-usando-arduino/ 


   HARDWARE Sensor de Umidade

   VCC+    -> 5V do Arduino
   GND     -> GND do Arduino
   A0      -> analógico 0 do Arduino
   
   
======================================================================================================== */


// ========================================================================================================
// --- Range de Umidade do Solo ---
#define    L1        169
#define    L2        340
#define    L3        511
#define    L4        682
#define    L5        853


// ========================================================================================================
// --- Mapeamento de Hardware ---
#define    analogi    A0
#define    digital    15
#define    gnd_pin    16
#define    vcc_pin    17


// ========================================================================================================
// --- Protótipo das Funções ---
void read_humidity(int level1, int level2, int level3, int level4, int level5);


// ========================================================================================================
// --- Variáveis Globais --- 
int adc_value = 0x00;


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
    Serial.begin(115200);
    
    pinMode(analogi,  INPUT);
    pinMode(digital,  INPUT);
    pinMode(gnd_pin, OUTPUT);
    pinMode(vcc_pin, OUTPUT);

    digitalWrite(gnd_pin,  LOW);
    digitalWrite(vcc_pin, HIGH);


} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{
 
    read_humidity(L1, L2, L3, L4, L5);                             //chama função que lê sensor de umidade
    delay(741);                                                    //taxa de atualização
    
  
} //end loop


// ========================================================================================================
// --- Desenvolvimento das Funções ---
void read_humidity(int level1, int level2, int level3, int level4, int level5)
{

  adc_value = analogRead(analogi);                                 //lê valor do sinal analógico e salva em adc_value
 
  Serial.print("Lendo Sensor: ");                                  //imprime no Serial Monitor
  Serial.print(adc_value);                                         //imprime no Serial Monitor
 
// ================================================================
  if (adc_value > 0 && adc_value < level1)             //identifica nível de umidade 0
  {
    Serial.println(" Status: Solo totalmente umido");

 
  }

// ================================================================
  else if (adc_value > level1 && adc_value < level2)   //identifica nível de umidade 1
  {
    Serial.println(" Status: Umidade media");

 
  }
 
// ================================================================
  else if (adc_value > level2 && adc_value < level3)   //identifica nível de umidade 2
  {
    Serial.println(" Status: Umidade minima");


  }


// ================================================================
  else if (adc_value > level3 && adc_value < level4)   //identifica nível de umidade 3
  {
    Serial.println(" Status: Solo secando");

 
  }


// ================================================================
  else if (adc_value > level4 && adc_value < level5)   //identifica nível de umidade 4
  {
    Serial.println(" Status: Solo quase seco");


  }


// ================================================================
  else if (adc_value > level5 && adc_value < 1024)     //identifica nível de umidade 5
  {
    Serial.println(" Status: Solo seco");


  }
  
  
} //end read_humidity
 
 





