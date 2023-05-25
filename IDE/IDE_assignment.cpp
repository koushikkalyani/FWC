#include<Arduino.h>
void setup(){
pinMode(13,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
}
void loop(){
boolean x = digitalRead(2);
boolean y = digitalRead(3);
boolean z = digitalRead(4);
boolean f = (!x && !z)||(y && !z);
if(f==1){
digitalWrite(13,HIGH);
 }
else{
digitalWrite(13,LOW);
 }
}
