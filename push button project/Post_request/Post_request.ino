#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

#define ssid  "TOPNET_6X6K6E"
#define pass  "6XFK6ETM6G"

#define btn1 16
#define btn2 5
#define btn3 4


int sensorValue1 = 0;       //sensor value, I'm usingg 0/1 button state
int sensorValue2 = 0;        
int sensorValue3 = 0;        


unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

int tableau[100] ; 

String sensorReadings;
int state = 0;              // used for storing what button was pressed
int inf=0;
int sup=0;

#define ssid  "TOPNET_6X6K6E"
#define pass  "6XFK6ETM6G"
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
pinMode(btn1, INPUT);
pinMode(btn2, INPUT);
pinMode(btn3, INPUT);
}

void loop() {
  // print the results to the Serial Monitor:
  readSwitch();
  Serial.print("State = ");
  Serial.println(state);
  delay(200);
  
  String Value = String(state);
 //Your Domain name with URL path or IP address with path
 String serverName = "http://192.168.1.203/test/testwsbt.php?statut="+Value;
   
  // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay){
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
  OutofConnection(tableau);
  delay(4000);
}
void readSwitch () {                                  //creates the function to read the switch states
 if (digitalRead(btn1) == LOW) 
    {sensorValue1 = 1; 
     state=1 ;
     delay(100);   }                     //delay for debounce purposes
   else {sensorValue1=0; }
   if (digitalRead(btn2) == LOW) 
    {sensorValue2 = 1; //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
     state=2 ;
     delay(100);                                       //delay for debounce purposes
  }
  else {sensorValue2=0 ;}
  if (digitalRead(btn3) == HIGH) 
    {sensorValue3 = 1; //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
     state=3 ;
     delay(100);                                       //delay for debounce purposes
  }
  else {sensorValue3=0 ;
        }
 delay(100);   //delay for timeing purpose 
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
      tableau[sup]= state; 
      sup++; 
      if (sup==99)
     
       {  deplace(inf ,sup );}
      }
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  
  // Free resources
  http.end();
   return payload;
}

void OutofConnection(int *tableau)
{ 
  while (WiFi.status()== WL_CONNECTED){
   for(int i=inf;i<=sup ;i++)
   {
    state=tableau[i];
    inf=i;}
  }
    String serverName = "http://192.168.1.203/test/testws.php?statut="+state;
   
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
}

     
void deplace( int inf , int sup)
{   int j=inf;
    int i=0;
   while ( j<sup )
    { tableau[i]=tableau[j];
      j++;
      i++;
   }
     sup=i;
}
   

  
  
