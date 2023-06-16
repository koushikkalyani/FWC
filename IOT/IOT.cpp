

//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "suresh"  // Replace with your network credentials
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
int p = 2;
int q = 3;
int r = 4;
int s = 5;
int f = 13;
void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
	//pinMode(2, OUTPUT);	
	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT);
	pinMode(5,INPUT);
	pinMode(13,OUTPUT);

}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  	//digitalWrite(2, HIGH);
	//delay(100);
	//digitalWrite(2, LOW);
	//delay(100);
	
  p = digitalRead(2);
  q = digitalRead(3);
  r = digitalRead(4);
  s = digitalRead(5);

  digitalWrite(13,LOW);
  
  f=(!r&&q)||(s);

  if(f == 1)
  {
	  digitalWrite(13,HIGH);
  }
  else
  {
	  digitalWrite(13,LOW);
  }
}


