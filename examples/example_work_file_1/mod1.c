#include <stdio.h>
#include "mod1.h"

void printMod1(){
    Led led = LED_ON;
    printf("this is mod1 | LED status: ");
    printLedStatus(led);
    printf("\n");
}