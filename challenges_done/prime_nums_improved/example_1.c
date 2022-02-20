#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MIN_UPPER_LIMIT 3
#define MAX_UPPER_LIMIT 1000000
#define PRIME_FOUND_LEN 100000
#define PRINTABLE_LIMIT 50

bool isPrimeSimple(int num){
    const int limit = sqrt(num);
    for(int i = 2; i <= limit; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

bool isPrimeOptimized(int num, int primeNums[], int found){
    const int limit = sqrt(num);

    for (int i = 0; i < found && primeNums[i] <= limit; i++){
        if(num % primeNums[i] == 0){
            return false;
        }
    }
    return true;
}

bool isPrime(int num, bool optimized, int primeNums[], int found){
    return optimized ? isPrimeOptimized(num, primeNums, found) : isPrimeSimple(num);
}

int getPrimeNums(int upperLimit, int primeNums[], bool optimized){
    int found = 0;
    for(int num = 2; num < upperLimit; num++){
        if(isPrime(num, optimized, primeNums, found)){
            primeNums[found] = num;
            found++;
        }
    }
    return found;
}

void printNumArray(int numAr[], int length){
    printf("found %d prime numbers:\n", length);
    for(int i = 0; i < length && i < PRINTABLE_LIMIT; i++){
        printf("%d ", numAr[i]);
    }
    printf("\n");
}

double elapsedTimeSecs(clock_t start, clock_t end){
    return (end - start) / (double)CLOCKS_PER_SEC;
}

int main(void)
{
    int upperLimit = 0;

    printf("enter an upper limit (min: %d | max: %d):\n", MIN_UPPER_LIMIT, MAX_UPPER_LIMIT);
    if(scanf("%d", &upperLimit) != 1 || upperLimit > MAX_UPPER_LIMIT || upperLimit < MIN_UPPER_LIMIT){
        printf("wrong input\n");
        return 1;
    }

    int found = 0, primeNumbers[PRIME_FOUND_LEN];
    clock_t startTime, endTime;

    startTime = clock();
    found = getPrimeNums(upperLimit, primeNumbers, false);
    endTime = clock();
    printf("\nsimple version elapsed time: %.1lf [ms]\n\n", elapsedTimeSecs(startTime, endTime) * 1e3);
    printNumArray(primeNumbers, found);

    startTime = clock();
    found = getPrimeNums(upperLimit, primeNumbers, true);
    endTime = clock();
    printf("\noptimized version elapsed time: %.1lf [ms]\n\n", elapsedTimeSecs(startTime, endTime) * 1e3);
    printNumArray(primeNumbers, found);

    return 0;
}