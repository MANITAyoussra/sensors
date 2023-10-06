#include <ESP8266WiFi.h> 
#include <DNSServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <Arduino_JSON.h>
#include <String.h>

//#define ssid  "TOPNET_6X6K6E" 
//#define pass  "6XFK6ETM6G"

#define ssid  "TOPNET_89C8" 
#define pass  "8vhev3m4nz"            

// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String sensorReadings;

// defines pins numbers
const int trigPin = 5;  //D4
const int echoPin = 4;  //D3
int counter=0;
// defines variables
long duration;
float distance,d;

float distanceF(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
delay(200);
return(distance);
}

void setup() {  // put your setup code here, to run once:
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
Serial.print("Connected to ");
Serial.println(ssid);
Serial.print("IP :");
Serial.println(WiFi.localIP());

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
Serial.println("bonjourrrrrrrrrrrrr");
// Clears the trigPin
while (distanceF()<20){
   delay(20);
}
while(true){
  while(distanceF()>=20){
   d=distanceF();
   }
while(distanceF()<=20){
  d=distanceF();
}
counter=counter+1 ;
Serial.println(counter);
 //Your Domain name with URL path or IP address with path
 String serverName = "http://192.168.1.203/test/testws.php?counter="+counter;
   
  // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      sensorReadings = httpGETRequest(serverName);
      delay(5000);    // every 5 s new value of temperature and humidity 
      Serial.println(sensorReadings);
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
  delay(6000);
}
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



