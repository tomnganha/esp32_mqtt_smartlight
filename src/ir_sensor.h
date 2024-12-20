#ifndef IR_SENSOR_HANDLER_H
#define IR_SENSOR_HANDLER_H

#include<Arduino.h>
#include "config.h"

extern const int NUM_LIGHTs;
extern String lightStates[];

void setUpIrSensors(){
     for (int i = 0; i < NUM_LIGHTs; i++) {
        pinMode(IR_SENSOR_PINS[i],INPUT);
  }
}


#endif