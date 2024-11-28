#ifndef LIGHT_HANDLER_H
#define LIGHT_HANDLER_H

#include<Arduino.h>
#include<ezButton.h>
#include "config.h"

extern const int NUM_LIGHTs;
extern String lightStates[];
extern ezButton buttons[];
extern const int NUM_LIGHTs;

void setUpLightsAndButton(){
    for (int i = 0; i < NUM_LIGHTs; i++) {
    pinMode(LIGHT_PINS[i], OUTPUT);
    //lightStates[i] = false;  // Initialize lights to OFF
    digitalWrite(LIGHT_PINS[i], LOW);
    buttons[i].setDebounceTime(50);
  }
}
void handleButtonPress(){
    for(int i=0;i<NUM_LIGHTs;i++){
        buttons[i].loop();
        if(buttons[i].isPressed()){
            lightStates[i]=(lightStates[i]=="on"?"off":"on");
            digitalWrite(LIGHT_PINS[i],lightStates[i]=="on" ? HIGH : LOW);
            sendToMQTT();  // Publish updated status to MQTT
        }
    }
}

#endif