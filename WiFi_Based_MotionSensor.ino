#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
 
// WiFi credentials
const char* ssid = "Shabir";
const char* password = "Awanhouse";
 
// ThingSpeak settings
unsigned long channelID = 2472655;
const char* apiKey = "7U6I3TRHO3GTUBQP";
 
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
