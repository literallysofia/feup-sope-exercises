#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char** argv) {

        char str[MAX_LENGTH];
        char* token;
        char* tokens[MAX_LENGTH];

        printf("Write a command : ");

        fgets(str, MAX_LENGTH, stdin);

        token = strtok(str," ");

        printf("\nTokens :\n");

        int i = 0;

        while(token != NULL) {
                tokens[i] = token;
                token = strtok(NULL," ");
                i++;
        }

        int j;

        for(j=0; j < i; j++) {
                printf("%s\n", tokens[j]);
        }
        exit(0);
}
