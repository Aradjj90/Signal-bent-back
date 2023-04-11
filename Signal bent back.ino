#include <iarduino_OLED_txt.h> 

iarduino_OLED_txt myOLED(0x3C);  

extern uint8_t MediumFontRus[];
byte flex = A0;
int data = 0;
#define buzzer 5
#define GNDbuzzer 2
#define VccforSensor 4
#define GNDforSensor 3
unsigned long timer;
int counter = 0;
#define pokaznuk 350

void setup() {
  Serial.begin(9600);
myOLED.begin();                                
myOLED.setFont(MediumFontRus);                                   
pinMode(buzzer,OUTPUT);
pinMode(GNDbuzzer,OUTPUT);
pinMode(VccforSensor,OUTPUT);
pinMode(GNDforSensor,OUTPUT);
pinMode(flex,INPUT);

digitalWrite(GNDbuzzer,LOW);
digitalWrite(VccforSensor,HIGH);
digitalWrite(GNDforSensor,LOW);

}

void loop() {
 LC();

while(data>pokaznuk){
counter++;
if( millis() - timer > 10000)analogWrite(buzzer,70);
LC();
if(counter>1)continue;
timer = millis();
}
if(flex<pokaznuk)analogWrite(buzzer,0);
timer = millis();
counter=0;
}
void LC (){
data = analogRead(flex);
Serial.println(data);
myOLED.clrScr();                                        
  myOLED.print(F("Data: "), 0, 4);
  myOLED.print(data);
  myOLED.print(F(";"));
delay(1000);
  
  }
