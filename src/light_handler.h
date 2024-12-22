#ifndef LIGHT_HANDLER_H
#define LIGHT_HANDLER_H

#include <Arduino.h>
#include <ezButton.h>
#include "config.h"
// #include "mqtt_handler.h"

extern const int NUM_LIGHTs;
extern String lightStates[];
extern ezButton buttons[];
extern const int NUM_LIGHTs;

void setUpLightsAndButton()
{
    for (int i = 0; i < NUM_LIGHTs; i++)
    {
        // pinMode(LIGHT_PINS[i], OUTPUT);
        ledcSetup(i, pwmFreq, pwmResolution);
        ledcAttachPin(LIGHT_PINS[i], i);
        // lightStates[i] = false;  // Initialize lights to OFF
        ledcWrite(i, 0);
        buttons[i].setDebounceTime(50);
    }
}
void handleButtonPress()
{
    
    for (int i = 0; i < NUM_LIGHTs; i++)
    {
        buttons[i].loop();
        if (buttons[i].isPressed())
        {
            lightStates[i] = (lightStates[i] == "on" ? "off" : "on");
            if (powerSavingMode == false)
            {
                ledcWrite(i, lightStates[i] == "on" ? 255 : 0);
            }
            else if (powerSavingMode == true)
            {
                ledcWrite(i,lightStates[i]=="on" ? brightness_normal : 0);
                
            }
            sendToMQTT(); // Publish updated status to MQTT
        }
    }
    
}
//bật đèn theo trạng thái status có sẵn
void resetLight()
{
    for (int i = 0; i < NUM_LIGHTs; i++)
    {
        if (powerSavingMode == false)
        {
            ledcWrite(i, lightStates[i] == "on" ? 255 : 0);
        }
        else if (powerSavingMode == true)
        {
            ledcWrite(i,lightStates[i]=="on" ? brightness_normal : 0);
           
        }
    }
}

void powerSavingModeHandler()
{
    for (int i = 0; i < NUM_LIGHTs; i++)
    {
        if (lightStates[i] == "on")
        {
            if (digitalRead(IR_SENSOR_PINS[i]) == LOW)
            {
                ledcWrite(i, 255);
            }
            else if (digitalRead(IR_SENSOR_PINS[i]) == HIGH)
            {
                ledcWrite(i, brightness_normal);
            }
        }
    }
}
void autoLightModeHandler(){
    int ldrModuleState=digitalRead(LDR_MODULE);
    if(ldrModuleState==HIGH&&(ldrModuleState!=ldrModuleLastState)){//troi toi
        for(int i=0;i<NUM_LIGHTs;i++){
            lightStates[i]="on";
        }
        resetLight();
        sendToMQTT(); // Publish updated status to MQTT
    }else if(ldrModuleState==LOW&&(ldrModuleState!=ldrModuleLastState)){//troi sang
        for(int i=0;i<NUM_LIGHTs;i++){
            lightStates[i]="off";
        }
        resetLight();
        sendToMQTT(); // Publish updated status to MQTT
    }
    ldrModuleLastState=ldrModuleState;
}
#endif