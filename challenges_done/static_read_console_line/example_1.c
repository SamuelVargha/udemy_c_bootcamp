#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 50

void clearStdIn(){
    int c = ' '; 
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}

int getLine(char dst[], int size){
    int i;
    for(i = 0; i < size - 1; i++){
        int c = getchar();
        if(c == '\n' || c == EOF){
            break;
        }else{
            dst[i] = (char) c;
        }
    }
    if(i == size - 1){
        clearStdIn();
    }
    dst[i] = '\0';
    return i;
}

int main(void){

    char buffer[BUF_SIZE];

    do{
        printf("enter a line:\n");
        int n = getLine(buffer, BUF_SIZE);
        printf("line = %s | number of characters: %d\n", buffer, n);
    }while(strcmp(buffer, "END") != 0);

    return 0;
}