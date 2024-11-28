#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi
const char WIFI_SSID[] = "T2";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "00009999";  // CHANGE TO YOUR WIFI PASSWORD

// MQTT
const char MQTT_BROKER_ADRRESS[] = "broker.hivemq.com";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "thai-esp32-001";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                        // CHANGE IT IF REQUIRED, empty if not required

// MQTT Topics
const char PUBLISH_TOPIC[] = "thai-esp32-001/loopback";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "thai-esp32-001/loopback";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

#endif
