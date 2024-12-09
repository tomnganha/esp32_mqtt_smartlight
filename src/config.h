#ifndef CONFIG_H
#define CONFIG_H
//C:\Users\Dell\data
// Wi-Fi
const char WIFI_SSID[] = "T2";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "00009999";  // CHANGE TO YOUR WIFI PASSWORD

// MQTT
//const char MQTT_BROKER_ADRRESS[] = "broker.hivemq.com";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "test.mosquitto.org";
const char MQTT_BROKER_ADRRESS[] = "04f4aeeea4d84429864135c7870eb612.s1.eu.hivemq.cloud";
const int MQTT_PORT = 8883;//1883
const char MQTT_CLIENT_ID[] = "thaipbl3532-esp32-001";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "thai";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "123456";                        // CHANGE IT IF REQUIRED, empty if not required

// MQTT Topics
const char PUBLISH_TOPIC[] = "pbl3-esp32-001/lights/status";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "pbl3-esp32-001/lights/control";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

//hardware configuration
const int BUTTON_PINS[] = {15, 16, 4, 18, 19}; // GPIO cho 5 nút nhấn
const int LIGHT_PINS[] = {17,22,23,25,26};         // GPIO cho 5 bóng đèn
// const int IR_SENSOR_PINS[]={5,12,13,14,27,33,32,35,34}
const int IR_SENSOR_PINS[]={27,32,33,34,35};

// Tần số PWM và độ phân giải
const int pwmFreq = 5000; // Tần số PWM 5 kHz
const int pwmResolution = 8; // Độ phân giải 8 bit (0-255)
bool powerSavingMode = true; // Giá trị ban đầu là tắt chế độ tiết kiệm điện
uint8_t brightness_normal=50;
uint8_t brightness_max=255;
//khi báo function
void setUpLightsAndButton();
void handleButtonPress();
void resetLight();
void sendToMQTT();
void messageHandler(String &topic, String &payload);
void connectToMQTT();
void connectToWiFi();
void powerSavingModeHandler();
#endif
