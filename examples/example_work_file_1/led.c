#include <stdio.h>
#include "led.h"

void printLedStatus(Led led){
    printf("status: %s", led == LED_ON ? "LED_ON" : "LED_OFF");
}