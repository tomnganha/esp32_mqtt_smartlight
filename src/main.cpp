// #include<header.h>
// #include<function.h>


// const char WIFI_SSID[] = "T2";     // CHANGE TO YOUR WIFI SSID
// const char WIFI_PASSWORD[] = "00009999";  // CHANGE TO YOUR WIFI PASSWORD

// const char MQTT_BROKER_ADRRESS[] = "broker.hivemq.com";  // CHANGE TO MQTT BROKER'S ADDRESS
// const int MQTT_PORT = 1883;
// const char MQTT_CLIENT_ID[] = "thai-esp32-001";  // CHANGE IT AS YOU DESIRE
// const char MQTT_USERNAME[] = "";                        // CHANGE IT IF REQUIRED, empty if not required
// const char MQTT_PASSWORD[] = "";                        // CHANGE IT IF REQUIRED, empty if not required

// // The MQTT topics that ESP32 should publish/subscribe
// const char PUBLISH_TOPIC[] = "thai-esp32-001/loopback";    // CHANGE IT AS YOU DESIRE
// const char SUBSCRIBE_TOPIC[] = "thai-esp32-001/loopback";  // CHANGE IT AS YOU DESIRE

// const int PUBLISH_INTERVAL = 5000;  // 5 seconds

// WiFiClient network;
// MQTTClient mqtt = MQTTClient(256);

// unsigned long lastPublishTime = 0;

// //tien khai bao ham
// // void connectToMQTT();
// // void sendToMQTT();
// // void messageHandler(String &topic, String &payload);
// void setup() {
//   Serial.begin(9600);

//   // set the ADC attenuation to 11 dB (up to ~3.3V input)
//   analogSetAttenuation(ADC_11db);

//    WiFi.mode(WIFI_STA);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//   Serial.println("ESP32 - Connecting to Wi-Fi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println();

//   connectToMQTT( mqtt,MQTT_BROKER_ADRRESS,  MQTT_PORT,network, MQTT_CLIENT_ID, MQTT_USERNAME,MQTT_PASSWORD,SUBSCRIBE_TOPIC);
// }

// void loop() {
//   mqtt.loop();

//   if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
//     sendToMQTT(mqtt, PUBLISH_TOPIC);
//     lastPublishTime = millis();
//   }
// }

// // void connectToMQTT() {
// //   // Connect to the MQTT broker
// //   mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

// //   // Create a handler for incoming messages
// //   mqtt.onMessage(messageHandler);

// //   Serial.print("ESP32 - Connecting to MQTT broker");

// //   while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
// //     Serial.print(".");
// //     delay(100);
// //   }
// //   Serial.println();

// //   if (!mqtt.connected()) {
// //     Serial.println("ESP32 - MQTT broker Timeout!");
// //     return;
// //   }

// //   // Subscribe to a topic, the incoming messages are processed by messageHandler() function
// //   if (mqtt.subscribe(SUBSCRIBE_TOPIC))
// //     Serial.print("ESP32 - Subscribed to the topic: ");
// //   else
// //     Serial.print("ESP32 - Failed to subscribe to the topic: ");

// //   Serial.println(SUBSCRIBE_TOPIC);
// //   Serial.println("ESP32 - MQTT broker Connected!");
// // }

// // void sendToMQTT() {
// //   JsonDocument message;
// //   message["timestamp"] = millis();
// //   message["data"] = analogRead(0);  // Or you can read data from other sensors
// //   char messageBuffer[512];
// //   serializeJson(message, messageBuffer);

// //   mqtt.publish(PUBLISH_TOPIC, messageBuffer);

// //   Serial.println("ESP32 - sent to MQTT:");
// //   Serial.print("- topic: ");
// //   Serial.println(PUBLISH_TOPIC);
// //   Serial.print("- payload:");
// //   Serial.println(messageBuffer);
// // }

// // void messageHandler(String &topic, String &payload) {
// //   Serial.println("ESP32 - received from MQTT:");
// //   Serial.println("- topic: " + topic);
// //   Serial.println("- payload:");
// //   Serial.println(payload);
// // }
#include <Arduino.h>
#include "config.h"
#include "wifi_handler.h"
#include "mqtt_handler.h"

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);
unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);

  connectToWiFi();
  connectToMQTT();
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
}
