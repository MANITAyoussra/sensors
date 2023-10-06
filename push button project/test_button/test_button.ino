#include <ESP8266WiFi.h> 

#define ssid  "TOPNET_6X6K6E"
#define pass  "6XFK6ETM6G"

#define btn1 16
#define btn2 5
#define btn3 4


int sensorValue1 = 0;       //sensor value, I'm usingg 0/1 button state
int sensorValue2 = 0;        
int sensorValue3 = 0;        
int state= 0;       


void setup() {
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
Serial.begin(115200);
while (WiFi.status()!= WL_CONNECTED){
  delay(500);
  Serial.print("."); }
Serial.println("");
Serial.print("Connected to");
Serial.println(ssid);
Serial.print("IP :");
Serial.println(WiFi.localIP());
pinMode(btn1, INPUT);
pinMode(btn2, INPUT);
pinMode(btn3, INPUT);
}
void loop(){
  // print the results to the Serial Monitor:
  readSwitch();
  Serial.print("sensorValue = ");
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  Serial.println(sensorValue3);
  Serial.print("State = ");
  Serial.println(state);
  delay(200);
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
