#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include <String.h>

#include "DHT.h"    
//#define DHTTYPE DHT11
#define DHTTYPE DHT22  //if you want to use the DHT22 

const int DHTPin = 5; //--> The pin used for the DHT11 sensor is Pin D1=Pin 5
DHT dht(DHTPin, DHTTYPE); //--> Initialize DHT sensor, DHT dht(Pin_used, Type_of_DHT_Sensor);


const char* ssid = "TOPNET_6X6K6E";
const char* password = "6XFK6ETM6G";

// Set your Static IP Address Settings
IPAddress subnet(255, 255, 255, 0);                  // Subnet Mask
IPAddress gateway(192, 168, 7, 254);                  // Default Gateway
IPAddress local_IP(192, 168, 7, 42);             // Static IP Address for ESP8266


//----------------------------------------Procedure for reading the temperature value of a DHT22 sensor
String handleDHT22Temperature() {
  float t = dht.readTemperature();  //--> Read temperature as Celsius (the default). If you want to read the temperature sensor in Fahrenheit, use this -> float t = dht.readTemperature (true);
  String Temperature_Value = String(t);
  if (isnan(t)) { //--> Check if any reads failed and exit early (to try again).  
    Serial.println("Failed to read from DHT sensor!");
  }
  else {
    Serial.print("DHT22 || Temperature : ");
    Serial.print(t);
    Serial.print(" || ");
  }
  return(Temperature_Value);
}
//----------------------------------------
//----------------------------------------Procedure for reading humidity values from DHT11 sensors
String handleDHT22Humidity() {
  float h = dht.readHumidity();
  String Humidity_Value = String(h);
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor !");
  }
  else {
    Serial.print("Humidity : ");
    Serial.println(h);
  }
  return(Humidity_Value);
}

//Your Domain name with URL path or IP address with path
//const char* serverName = "http://192.168.1.203/test/testws.php?temperature=40&humidity=30";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

String sensorReadings;
//String sensorReadings1;
//float sensorReadingsArr[3];

void setup() {
 Serial.begin(115200);
  delay(500);
  dht.begin();  //--> Start reading DHT11 sensors
  delay(500);
   if (WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("Static IP Configured");
  }
  else {
    Serial.println("Static IP Configuration Failed");
  }
  
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");
  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  //----------------------------------------If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  String t=handleDHT22Temperature();
  String h=handleDHT22Humidity();
  
   String serverName = "http://192.168.7.28/test/testws.php?temperature="+t+'&'+"humidity="+h;
   // String serverName1 = "http://192.168.1.203/test/testws.php?humidity="+h;
   
  // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      sensorReadings = httpGETRequest(serverName);
      delay(120000);    // every 1min  new value of temperature and humidity 
      Serial.println(sensorReadings);
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
  delay(4000);
}

String httpGETRequest(String serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
  
}
