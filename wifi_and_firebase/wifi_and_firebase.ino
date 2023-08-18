
// Importing Libraries
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>

// Defining Wifi and Database
#define WIFI_SSID "Wifi_5002"
#define WIFI_PASSWORD "sentiatik"
#define FIREBASE_HOST "https://smartmeter-db412-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "f6f70c67909f3414d0136c39b75c61cd11ea7840"

// Initialize Firebase ESP8266 Client
FirebaseData firebaseData;
FirebaseJson json;

#define led1 D6
#define led2 D7

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

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}
  

void loop() {
  float value =0;
  digitalWrite(led1, HIGH); // Turn the LED on
  delay(1000);                // Wait for a second
  digitalWrite(led1, LOW);  // Turn the LED off
  delay(1000);                // Wait for a second


  // Firebase code 
// Data Read
  if (Firebase.getFloat(firebaseData, "/path/to/data")) {
    value = firebaseData.floatData();
    Serial.print("Read value from Firebase: ");
    Serial.println(value);
    Serial.print("\n");
  } else {
    Serial.println("Failed to read data from Firebase \n");
  }

// Data Write
  // if (Firebase.setFloat(firebaseData, "/path/to/data", 3.14)) {
  //   Serial.println("Data written to Firebase \n");
  // } else {
  //   Serial.println("Failed to write data to Firebase \n");
  // }

  if(value == 15){
    digitalWrite(led2,HIGH);
  }else{
    digitalWrite(led2,LOW);
  }
  
}




