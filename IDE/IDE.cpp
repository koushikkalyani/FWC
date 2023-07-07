#include <Arduino.h>
bool a0,a1,b0,b1;
byte a=0;
byte b=0;
void setup(){
pinMode(13,OUTPUT);
pinMode(2,INPUT);
pinMode(4,INPUT);
pinMode(6,INPUT);
pinMode(8,INPUT);}

void loop(){
a0=digitalRead(4);
a1=digitalRead(2);
b0=digitalRead(8);
b1=digitalRead(6);
a=(a1<<1)|a0;
b=(b1<<1)|b0;
if(a>b){
digitalWrite(13,HIGH);}
else{
digitalWrite(13,LOW);}
}
