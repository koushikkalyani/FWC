#include<Arduino.h>
void setup(){
pinMode(13,OUTPUT);
pinMode(2,INPUT);
pinMode(4,INPUT);
pinMode(6,INPUT);
pinMode(8,INPUT);
}

void loop(){
bool a0=digitalRead(4);
bool a1=digitalRead(2);
bool b0=digitalRead(8);
bool b1=digitalRead(6);
bool f=(a1&&!b1)||(a1&&a0&&!b0)||(a0&&!b0&&!b1);
if(f==1){
digitalWrite(13,HIGH);}
else{digitalWrite(13,LOW);}
}
