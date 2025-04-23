#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
 
// WiFi credentials
const char* ssid = "Wi-Fi Name";              // Write name of your Wi-Fi inside double comma
const char* password = "Wi-Fi Password";      // Write password of your Wi-Fi inside double comma
 
// ThingSpeak settings
unsigned long channelID = [Channel-ID];         // Write your Thing Speak channel ID removing square bracket
const char* apiKey = "API Key";               // Write your API Key inside double comma 
 
// PIR sensor pin
const int pirPin = D2;
 
// Initialize the client library
WiFiClient client;
 
void setup() {
  // Initialize serial communication
  Serial.begin(115200);
 
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
 
  // Initialize ThingSpeak
  ThingSpeak.begin(client);
  
  // Initialize PIR sensor pin as input
  pinMode(pirPin, INPUT);
 
  // Wait for sensor to settle
  delay(2000);
}
 
void loop() {
  // Read PIR sensor value
  int pirValue = digitalRead(pirPin);
 
  // Print PIR sensor value
  Serial.print("PIR Value: ");
  Serial.println(pirValue);
  if (pirValue == HIGH) {
    Serial.println("Motion Detected!");
  } else {
    Serial.println("No Motion");
  }
  // Send data to ThingSpeak
  ThingSpeak.writeField(channelID, 1, pirValue, apiKey);
 
  // Wait before sending the next update
 
    //delay(15000); // Send data every 15 seconds
}
