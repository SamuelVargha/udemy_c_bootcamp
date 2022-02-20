#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void rookPoor(char currentPos[], char outputBuffer[]){
    const char cols[] = "abcdefgh";
    const char rows[] = "12345678";

    char curCol = currentPos[0];
    char curRow = currentPos[1];
    char *dest = outputBuffer;

    for(const char *p = cols; *p != '\0'; p++){
        if(*p != curCol){
            *dest++ = *p;
            *dest++ = curRow;
            *dest++ = ' ';
        }
    }

    for(const char *p = rows; *p != '\0'; p++){
        if(*p != curRow){
            *dest++ = curCol;
            *dest++ = *p;
            *dest++ = ' ';
        }
    }

    *dest = '\0';
}

void rook(char currentPos[], char outputBuffer[]){
    const char cols[] = "abcdefgh";
    const char rows[] = "12345678";

    char curCol = currentPos[0];
    char curRow = currentPos[1];
    char *dest = outputBuffer;

    for(const char *c = cols, *r = rows; *c != '\0' || *r != '\0'; *c != '\0' ? c++ : r++){
        if(*c != curCol && *r != curRow){
            *dest++ = *c != '\0' ? *c : curCol;
            *dest++ = *c != '\0' ? curRow : *r;
            *dest++ = ' ';
        }
        *dest = '\0';
    }
}

void rookTwo(char currentPos[], char outputBuffer[]){
    const char cols_rows[] = "abcdefgh12345678";

    char curCol = currentPos[0];
    char curRow = currentPos[1];
    char *dest = outputBuffer;

    for(const char *p = cols_rows; *p != '\0'; p++){
        if(*p != curRow && *p != curCol){
            *dest++ = isdigit(*p) ? curCol : *p;
            *dest++ = isdigit(*p) ? *p : curRow;
            *dest++ = ' ';
        }
    }
}

void printBuffer(const char pos[], const char buffer[]){
    printf("==============================\n");
    printf("current position: %s\n", pos);
    printf("you can move to: %s\n", buffer);
    printf("==============================\n");
}

int main(void){

    char pos[] = "d5";
    char buffer[100];

    rookPoor(pos, buffer);
    printBuffer(pos, buffer);

    strcpy(pos, "e2");
    rook(pos, buffer);
    printBuffer(pos, buffer);

    rookTwo(pos, buffer);
    printBuffer(pos, buffer);

    return 0;
}