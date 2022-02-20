#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Zone{
    int id;
    double lowThresh;
    char *desc;
} Zone;

double calcMaxHeartRate(int age){
    return 208 - 0.7 * age;
}

void printRow(int id, double lowThresh, double highThresh, char desc[]){
    printf("%d | %3.0f - %3.0f | %s\n", id, lowThresh, highThresh, desc);
}

void printTable(Zone *zones, int length, double heartRateMax){
    printf("\n");
    for(Zone *z = zones; z < zones + length; z++){
        double highT = z < zones + length - 1 ? (z + 1)-> lowThresh * heartRateMax : heartRateMax;
        printRow(z->id, z->lowThresh * heartRateMax, highT, z->desc);
    }
    printf("\n");
}

Zone *findZone(Zone *zones, int zonesLength, double heartRateNow, double heartRateMax){
    for(int i = zonesLength - 1; i >= 0; i--){
        if(heartRateNow > zones[i].lowThresh * heartRateMax){
            return &zones[i];
        }
    }
    return NULL;
}

void printZone(Zone *zone){
    printf("zone %d | %s\n\n", zone->id, zone->desc);
}


int main ( void ){

    Zone zones[] = {
        {.id = 1, .lowThresh = 0, .desc = "rest"},
        {.id = 2, .lowThresh = 0.5, .desc = "very light work"},
        {.id = 3, .lowThresh = 0.6, .desc = "light cardio"},
        {.id = 4, .lowThresh = 0.7, .desc = "moderate work"},
        {.id = 5, .lowThresh = 0.8, .desc = "hard work"},
        {.id = 6, .lowThresh = 0.9, .desc = "peak performance"},
    };

    int zonesLength = sizeof(zones) / sizeof(zones[0]);
    int age;

    printf("enter your age: ");
    if(scanf("%d", &age) != 1){
        printf("wrong input\n");
        return 1;
    }

    double heartRateMax = calcMaxHeartRate(age);
    printf("max heartrate = %.0f\n", heartRateMax);

    printTable(zones, zonesLength, heartRateMax);

    while(1){
        double heartRateNow;
        printf("enter the current heart rate:\n");

        if(scanf("%lf", &heartRateNow) != 1){
            printf("wrong input\n");
            return 1;
        }else if(heartRateNow == 0){
            printf("quitting...\n");
            return 0;
        }
        
        Zone *currentZone = findZone(zones, zonesLength, heartRateNow, heartRateMax);
        if(currentZone){
           printZone(currentZone);
        }else{
            printf("cant find zone\n");
        }
    }

    return 0;
}