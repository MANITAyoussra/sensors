#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>


#define ssid  "TOPNET_6X6K6E"
#define pass  "6XFK6ETM6G"

//#define ssid  "Yousss"
//#define pass  "manita123"

#define PIN_BUTTON0 5
#define PIN_BUTTON1 4
#define PIN_BUTTON2 0

void setup() {
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
Serial.begin(115200);
while (WiFi.status()!= WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.print("Connected to");
Serial.println(ssid);
Serial.print("IP :");
Serial.println(WiFi.localIP());
//push button
pinMode(PIN_BUTTON0,INPUT);
pinMode(PIN_BUTTON1,INPUT);
pinMode(PIN_BUTTON2,INPUT);
}
void loop() {
  int buttonState0= 0;
  int buttonState1= 0;
  int buttonState2= 0;
  
  buttonState0= digitalRead(PIN_BUTTON0);
   if (buttonState0==1) {
   Serial.println("button 0 is pressed ");}
   if (buttonState0==0) {
   Serial.println("button not pressed ");}
   
   buttonState1= digitalRead(PIN_BUTTON1);
   buttonState2= digitalRead(PIN_BUTTON2);
   if (buttonState1== HIGH) {
   Serial.println("button 1 is pressed ");}
   if (buttonState2== HIGH) {
   Serial.println("button 2 is pressed ");}*/
   delay(3000);

}
