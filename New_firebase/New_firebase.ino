#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>

// Defining Wifi and Database
#define WIFI_SSID "Wifi_5002"
#define WIFI_PASSWORD "sentiatik"
#define FIREBASE_HOST "https://smartmeter2-85065-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "0ea0a18b38d179a9fae868041eac00374e3e576f"
 
// Initialize Firebase ESP8266 Client
FirebaseData firebaseData;
FirebaseJson json;


#define led1 D5
#define led2 D6
#define led3 D7

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.SSID());
  Serial.println("\n");

  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}
  

void loop() {
  bool load1 =false;
  bool load2 = false;
  bool load3 =  false;


  // Firebase code 
// Data Read
  if (Firebase.getBool(firebaseData, "/Users/user01/loads/1/load1")) {
    Firebase.getBool(firebaseData, "/Users/user01/loads/0/load1");
    load1=firebaseData.boolData();
    Firebase.getBool(firebaseData, "/Users/user01/loads/1/load1");
    load2=firebaseData.boolData();
    Firebase.getBool(firebaseData, "/Users/user01/loads/2/load1");
    load3=firebaseData.boolData();
    //value = firebaseData.boolData();
    Serial.print("Read value from Firebase: \n");
  

  } else {
    Serial.println("Failed to read data from Firebase \n");
  }




  if(load1 == 1){
    digitalWrite(led1,HIGH);
  }else{
    digitalWrite(led1,LOW);
  }

    if(load2 == 1){
    digitalWrite(led2,HIGH);
  }else{
    digitalWrite(led2,LOW);
  }

    if(load3 == 1){
    digitalWrite(led3,HIGH);
  }else{
    digitalWrite(led3,LOW);
  }
  
}




