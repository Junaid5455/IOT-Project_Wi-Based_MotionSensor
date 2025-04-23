# 🚨 PIR Motion Detection using ESP8266 and ThingSpeak

This project uses a **PIR motion sensor** connected to a **NodeMCU ESP8266** to detect motion and send real-time data to **ThingSpeak**, a cloud-based IoT analytics platform. The data can be monitored via the **ThingSpeak dashboard or mobile app**, making it ideal for basic **home security** and **motion detection applications**.

---

## 📌 Features

- Detects motion using a PIR sensor (e.g., HC-SR501).
- Sends real-time sensor data to ThingSpeak.
- View motion status remotely via **ThingSpeak web dashboard** or app.
- Serial Monitor outputs real-time status for debugging and local monitoring.
- Wi-Fi-based IoT implementation (no additional gateway needed).

---

## 🧰 Hardware Requirements

| Component              
..........................
| NodeMCU ESP8266 Board  
| PIR Motion Sensor (e.g., HC-SR501)
| Jumper Wires          
| Breadboard or PCB      
| 5V USB Power Supply    

---

## 🔌 Wiring Setup

| PIR Sensor Pin | ESP8266 Pin |
|----------------|-------------|
| VCC            | 3.3V        |
| GND            | GND         |
| OUT            | D2 (GPIO4)  |

---

## 🔧 Configuration

1. Replace these placeholders in the code with your actual credentials:

const char* ssid = "Your-WiFi-Name";
const char* password = "Your-WiFi-Password";

unsigned long channelID = YOUR_CHANNEL_ID;
const char* apiKey = "Your-ThingSpeak-API-Key";

