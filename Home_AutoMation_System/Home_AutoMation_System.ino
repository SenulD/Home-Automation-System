#include "FirebaseESP32.h"       // include firebase library

const char* ssid = "Your wifi ssid";
const char* password = "Your password";

FirebaseData firebaseData;

int LED_BUILTIN = 2;
float pin1 = 23;
float pin2 = 22;
float pin3 = 18;
float pin4 = 19;
float pin5 = 5;
float pin6 = 4;
float pin7  = 15;

void setup() {

  Serial.begin(9600);  connectWifi();
  Firebase.begin("Firebase URL ", "Secret key");


  pinMode (LED_BUILTIN, OUTPUT); //BULLTIN LED
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
}

void loop() {

if(Firebase.get(firebaseData,"/Blootooth/Connect")) {
  if (firebaseData.dataType() == "string") {
    if (firebaseData.stringData() ==  ("\"10\"")){
      Serial.println(firebaseData.stringData());
      if(Firebase.get(firebaseData,"/Blootooth/hello")) {
       if (firebaseData.dataType() == "string") {
        Serial.println(firebaseData.stringData());

              // on with wifi 01
      if (firebaseData.stringData() ==  ("\"0\"")){
         
         digitalWrite(LED_BUILTIN, HIGH);
      
      }
      if (firebaseData.stringData() ==  ("\"1\"")){
         
         digitalWrite(LED_BUILTIN, LOW);
      }
      // on fiwi 02
      if (firebaseData.stringData() ==  ("\"2\"")){
         
         digitalWrite(pin1,HIGH);
      }
      if (firebaseData.stringData() ==  ("\"3\"")){
         
         digitalWrite(pin1, LOW );
      }
      // on fiwi 03
      if (firebaseData.stringData() ==  ("\"4\"")){
         
         digitalWrite(pin2, HIGH);
      }
      if (firebaseData.stringData() ==  ("\"5\"")){
         
         digitalWrite(pin2,  LOW);
      }
      // on wifi04
      if (firebaseData.stringData() ==  ("\"6\"")){
         
         digitalWrite(pin3, HIGH);
      }
      if (firebaseData.stringData() ==  ("\"7\"")){
         
         digitalWrite(pin3,  LOW);
      }
            // on wifi05
      if (firebaseData.stringData() ==  ("\"8\"")){
         
         digitalWrite(pin5, HIGH);
      }
      if (firebaseData.stringData() ==  ("\"9\"")){
         
         digitalWrite(pin5,  LOW);
      }
                  // on wifi06
      if (firebaseData.stringData() ==  ("\"10\"")){
         
         digitalWrite(pin4, HIGH);
      }
      if (firebaseData.stringData() ==  ("\"11\"")){
         
         digitalWrite(pin4,  LOW);
      }

    else{
      // for any other program to run when not connected to firebase.
      
            }
          }
        }
       }
      }
    }
  }

void connectWifi() {
  // Let us connect to WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(".......");
  Serial.println("WiFi Connected....IP Address:");
  Serial.println(WiFi.localIP());

}
