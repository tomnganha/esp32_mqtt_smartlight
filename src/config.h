#ifndef CONFIG_H
#define CONFIG_H

//define cha LDR module
#define LDR_MODULE 13
#define ACS_MODULE 34
 //C:\Users\Dell\data
// Wi-Fi
const char WIFI_SSID[] = "T2";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "00009999";  // CHANGE TO YOUR WIFI PASSWORD

// MQTT

const char MQTT_BROKER_ADRRESS[] = "04f4aeeea4d84429864135c7870eb612.s1.eu.hivemq.cloud";
const int MQTT_PORT = 8883;//1883
const char MQTT_CLIENT_ID[] = "thaipbl3532-esp32-001";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "thai";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "123456";                        // CHANGE IT IF REQUIRED, empty if not required

// MQTT Topics
const char PUBLISH_TOPIC[] = "pbl3-esp32-001/lights/status";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "pbl3-esp32-001/lights/control";  // CHANGE IT AS YOU DESIRE
const int PUBLISH_INTERVAL = 5000;  // 5 seconds

//tinh nang giam sat dien tieu thu

unsigned long previousCurrentMillis = 0;  // Thời gian trước đó (sử dụng millis)
unsigned long intervalCurrent = 10000;    // 1 phút (60,000 ms)
//hardware configuration
const int BUTTON_PINS[] = {19, 18, 16, 15, 4}; // GPIO cho 5 nút nhấn
const int LIGHT_PINS[] = {26,25,12,17,23};         // GPIO cho 5 bóng đèn
// const int IR_SENSOR_PINS[]={5,12,13,14,27,33,32,35,34}
const int IR_SENSOR_PINS[]={35,14,32,27,33};

// Tần số PWM và độ phân giải
const int pwmFreq = 5000; // Tần số PWM 5 kHz
const int pwmResolution = 8; // Độ phân giải 8 bit (0-255)
bool powerSavingMode = false; // Giá trị ban đầu là tắt chế độ tiết kiệm điện
bool autoLightMode=false;// giá trị ban đầu của chế độ bật đèn theo cảm biến ánh sáng
int ldrModuleLastState;
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
void setUpLDRModule();
void autoLightModeHandler();

#endif
