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
const char PUBLISH_TOPIC[] = "pbl3-esp32-001/lights/status";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "pbl3-esp32-001/lights/control";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

//hardware configuration
const int BUTTON_PINS[] = {15, 16, 4, 18, 19}; // GPIO cho 5 nút nhấn
const int LIGHT_PINS[] = {17,22,23,25,26};         // GPIO cho 5 bóng đèn

#endif
