//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "koushik"  // Replace with your network credentials
#define STAPSK  "12345678"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
bool R,S,P,Q,F;
void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
  pinMode(2,INPUT);   
  pinMode(3,INPUT);   
  pinMode(4,INPUT);   
  pinMode(5,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  OTAloop();
  R=digitalRead(2);
  S=digitalRead(4);
  P=digitalRead(6);
  Q=digitalRead(8);
  F=S||(!R&&Q);
if(F){  digitalWrite(13,HIGH);}
else {digitalWrite(13,LOW);}
}




