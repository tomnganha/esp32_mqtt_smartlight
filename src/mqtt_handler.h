#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "config.h"

extern WiFiClient network;
extern MQTTClient mqtt;
extern unsigned long lastPublishTime;
extern const int NUM_LIGHTs;
extern String lightStates[];
// extern const char PUBLISH_TOPIC[];
// extern const char SUBSCRIBE_TOPIC[];
// void messageHandler(String &topic, String &payload) {
//   Serial.println("ESP32 - received from MQTT:");
//   Serial.println("- topic: " + topic);
//   Serial.println("- payload:");
//   Serial.println(payload);
// }
void sendToMQTT()
{
  JsonDocument status;
  // message["timestamp"] = millis();
  // message["data"] = analogRead(0);  // Or you can read data from other sensors
  // char messageBuffer[512];
  // serializeJson(message, messageBuffer);

  // mqtt.publish(PUBLISH_TOPIC, messageBuffer);

  // Serial.println("ESP32 - sent to MQTT:");
  // Serial.print("- topic: ");
  // Serial.println(PUBLISH_TOPIC);
  // Serial.print("- payload:");
  // Serial.println(messageBuffer);
  for (int i = 0; i < NUM_LIGHTs; i++)
  {
    // status[String("light") + i] = lightStates[i];
    status[String("light") + i] = lightStates[i];
  }
  char payload[256];
  serializeJson(status, payload);
  mqtt.publish(PUBLISH_TOPIC, payload);

  Serial.println("Published light status:");
  Serial.println(payload);
}

void messageHandler(String &topic, String &payload)
{
  if (topic == SUBSCRIBE_TOPIC)
  {
    JsonDocument controlMessage;
    deserializeJson(controlMessage, payload);

    for (int i = 0; i < NUM_LIGHTs; i++)
    {
      String lightKey = String("light") + i;
      // if (controlMessage[lightKey].is<bool>()) {
      //   lightStates[i] = controlMessage[lightKey];
      //   digitalWrite(LIGHT_PINS[i], lightStates[i] ? HIGH : LOW);
      // }
      if (controlMessage[lightKey].is<const char *>())
      {
        lightStates[i] = controlMessage[lightKey].as<String>();
        ///digitalWrite(LIGHT_PINS[i], lightStates[i] == "on" ? HIGH : (lightStates[i] == "off" ? LOW : lightStates[i]));
         // Điều khiển đèn
            if (lightStates[i] == "on") {
                digitalWrite(LIGHT_PINS[i], HIGH);
            } else if (lightStates[i] == "off") {
                digitalWrite(LIGHT_PINS[i], LOW);
            } else {
                Serial.println("Invalid light state: " + lightStates[i]);
            }
      }
    }

    sendToMQTT(); // Update status after applying changes
  }
}
void connectToMQTT()
{
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
  mqtt.onMessage(messageHandler);

  Serial.print("ESP32 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD))
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected())
  {
    Serial.println("ESP32 - MQTT broker Timeout!");
    return;
  }

  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("ESP32 - Subscribed to the topic: ");
  else
    Serial.print("ESP32 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("ESP32 - MQTT broker Connected!");
}

#endif
