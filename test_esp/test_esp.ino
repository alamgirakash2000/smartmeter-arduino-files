// Pin connected to the LED
const int ledPin = D7;  // You can use any digital pin, adjust as needed
const int ledPin2= D6;

void setup() {
  pinMode(ledPin, OUTPUT);  // Initialize the LED pin as an output
  pinMode(ledPin2, OUTPUT);  // Initialize the LED pin as an output
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  digitalWrite(ledPin2, HIGH); // Turn the LED on
  delay(1000); 
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);                // Wait for a second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);                // Wait for a second

  // Optional: Print messages to serial monitor for debugging
  Serial.println("LED Blinking...");
}
