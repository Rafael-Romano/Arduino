#define pin1 7


int i = 5;
void setup() {
pinMode(pin1, OUTPUT);


}

void loop() {

for(i=5;i<500;i++){
 
digitalWrite( pin1, LOW);

delay(i);
digitalWrite( pin1, HIGH);

delay(i/10);

 i=i+20;}

}
