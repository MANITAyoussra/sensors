#include <ESP8266WiFi.h> 
#include "parameters.h"
#include "display.h"
#include "co2.h"

#include "network.h"
 #define ssid  "wifiID" 
#define pass  "password"

void setup() {

 
// put your setup code here, to run once:
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
Serial.begin(115200);
Serial.println("hello");

while (WiFi.status()!= WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.print("Connected to");
Serial.println(ssid);
Serial.print("IP :");
Serial.println(WiFi.localIP());
  Serial.begin(115200);
  delay(500);
  Serial.println("eCO2 sensor");
  setupScreen();
  setupCo2();
  setupThermometer();
}

uint16_t serialIdx = 1; // set to one to avoid sending first imprecise reading

void loop() {
  
 
  unsigned int co2 = getCo2(temperature, humidity);
  displayData(temperature, humidity, co2);
  if (serialIdx++ % 12 == 0) {
    Serial.printf("Update: temp: %.1f c - humitidy: %.0f - co2: %i\n", temperature, humidity, co2);
    #ifdef WIFI_SSID
    if (connectToWifi(WIFI_SSID, WIFI_PASSWORD)) {
       sendMetrics(temperature, humidity, co2);
    }
    #endif
  }
  delay(2500);
}
