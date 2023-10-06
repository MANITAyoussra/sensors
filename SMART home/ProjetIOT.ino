//----------------------------------------Include the NodeMCU ESP8266 Library
#include <ESP8266WiFi.h>
//#include "MQ2.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include<string.h>
//----------------------------------------

#include "DHT.h"  //--> Include the DHT Sensor Library 
#define DHTTYPE DHT11 //--> Defines the type of DHT sensor used (DHT11, DHT21, and DHT22), in this project the sensor used is DHT11.

#include "PageIndex.h" //--> Include the contents of the User Interface Web page, stored in the same folder as the .ino file

int SENSOR_OUTPUT_PIN = 5;

const int buzzer =  13;
//----------------------------------------SSID and Password of your WiFi router
char ssid[] = "Airbox-343A";
char password[] = "EJJBHJmJ";
//----------------------------------------
String person;
//char ssid[] = "iPhone de Menyara";
//char password[] = "Menza1111";
ESP8266WebServer server(80);  //--> Server on port 80

const int DHTPin = 4; //--> The pin used for the DHT11 sensor is Pin D1=Pin 5
DHT dht(DHTPin, DHTTYPE); //--> Initialize DHT sensor, DHT dht(Pin_used, Type_of_DHT_Sensor);

//----------------------------------------This routine is executed when you open NodeMCU ESP8266 IP Address in browser
void handleRoot() {
 String s = MAIN_page; //--> Read HTML contents
 server.send(200, "text/html", s); //--> Send web page
}
//----------------------------------------
//----------------------------------------Procedure for reading the temperature value of a DHT11 sensor
void handleDHT11Temperature() {
  float t = dht.readTemperature();  //--> Read temperature as Celsius (the default). If you want to read the temperature sensor in Fahrenheit, use this -> float t = dht.readTemperature (true);
  String Temperature_Value = String(t);
 
  server.send(200, "text/plane", Temperature_Value); //--> Send Temperature value only to client ajax request
  
  if (isnan(t)) { //--> Check if any reads failed and exit early (to try again).  
    Serial.println("Failed to read from DHT sensor!");
  }
  else {
    Serial.print("DHT11 || Temperature : ");
    Serial.print(t);
    Serial.print(" || ");
  }
}
//----------------------------------------
//----------------------------------------Procedure for reading humidity values from DHT11 sensors
void handleDHT11Humidity() {
  float h = dht.readHumidity();
  String Humidity_Value = String(h);
 
  server.send(200, "text/plane", Humidity_Value); //--> Send Humidity value only to client ajax request
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor !");
  }
  else {
    Serial.print("Humidity : ");
    Serial.println(h);
  }
}

//----------------------------------------
//----------------------------------------Setup




void setup(void){
  Serial.begin(115200);
  delay(500);
  dht.begin();  //--> Start reading DHT11 sensors
  delay(500);
  
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");

  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(buzzer, OUTPUT);
  pinMode (SENSOR_OUTPUT_PIN, INPUT);
  // sensor output pin to PIN DI of NODE MCU
  // pinMode (LED, OUTPUT) ;
//led output PIN D4 Of NODE MCU

  //----------------------------------------
  server.on("/", handleRoot); //--> Routine to handle at root location. This is to display web page.
  server.on("/readTemperature", handleDHT11Temperature);  //--> Routine to handle the call procedure handleDHT11Temperature
  server.on("/readHumidity", handleDHT11Humidity);  //--> Routine to handle the call procedure handleDHT11Humidity
  server.begin(); //--> Start server
  Serial.println("HTTP server started");
}
//----------------------------------------
//----------------------------------------Loop
void loop(){
  server.handleClient();  //Handle client requests
  
  int sensorvalue = digitalRead (SENSOR_OUTPUT_PIN);

  if (sensorvalue==1)
  { 
    digitalWrite(buzzer, HIGH);
    person = "person detected";
  Serial.println ("person dected ");
  }
  else {
  person ="  ";
  Serial.println ("no person detected");
  digitalWrite(buzzer, LOW);
  
  }
 delay(1000);

}


//----------------------------------------
