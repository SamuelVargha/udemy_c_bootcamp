#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getLineAlloc(int *lengthPointer){
    if(lengthPointer == NULL){
        //user doesnt care about the length of line
        lengthPointer = (int *) malloc(sizeof(*lengthPointer));
        if(lengthPointer == NULL){
            printf("cannot allocate memory\n");
            return NULL;
        }
    }
    *lengthPointer = 0;

    char *line = NULL;
    int bufferSize = 0, input;
    const int allocBlockSize = 5;

    while(1){
        input = getchar();

        if(bufferSize <= *lengthPointer){
            //resize the memory block
            bufferSize += allocBlockSize;
            char *reallocLine = realloc(line, bufferSize);
            if(reallocLine == NULL){
                printf("cannot allocate memory\n");
                free(line);
                return NULL;
            }
            //reallocation done
            line = reallocLine;
        }

        if(input != '\n' && input != EOF){
            line[(*lengthPointer)++] = (char) input;
        }else{
            break;
        }
    }
    line[*lengthPointer] = '\0';
    return line;

}

int main(void){

    char *line = NULL;
    int length = -1;

    do{
        printf("enter a line or (END) to exit:\n");

        free(line);
        line = getLineAlloc(&length);

        if(line == NULL){
            printf("cannot allocate memory\n");
        }else{
            printf("line: %s | length: %d\n", line, length);
        }

    }while(line != NULL && strcmp(line, "END") != 0);

    return 0;
}