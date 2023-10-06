#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

const int analogInPin = A0;

#define ssid  "TOPNET_6X6K6E"
#define pass  "6XFK6ETM6G"

//#define ssid  "Yousss"
//#define pass  "manita123"


int sensorValue = 0;        // value read from the buttons
int state = 0;              // used for storing what button was pressed

void setup() {
//wifi set up 
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
pinMode(analogInPin, INPUT); 
}

void loop() {
  // print the results to the Serial Monitor:
  readSwitch();
  Serial.print("Value = ");
  Serial.println(sensorValue);
  Serial.print("State = ");
  Serial.println(state);
  delay(200);
} 
void readSwitch () {                                  //creates the function to read the switch states
  sensorValue = analogRead(analogInPin);              //read the analog pin the switches are connected to 
   if (sensorValue < 424 && sensorValue > 0 ){       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 3 ;
    delay(100);                                       //delay for debounce purposes
  }
   if (sensorValue < 749 && sensorValue > 650) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 1;
    delay(100);                                       //delay for debounce purposes
  }

  if (sensorValue < 649 && sensorValue > 425) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 2;
    delay(100);
    }
   if (sensorValue < 1500 && sensorValue > 750 ) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 0;
    delay(100);
  }
 delay(1);                                           //delay for timeing purposes
}
