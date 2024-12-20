#ifndef LDR_MODULE_HANDLER_H
#define LDR_MODULE_HANDLER_H

#include<Arduino.h>
#include "config.h"

void setUpLDRModule(){
    pinMode(LDR_MODULE,INPUT);
}


#endif