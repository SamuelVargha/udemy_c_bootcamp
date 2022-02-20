#include <stdio.h>
#include "mod2.h"

void printMod2(){
    Led led = LED_OFF;
    printf("this is mod2 | LED status: ");
    printLedStatus(led);
    printf("\n");
}