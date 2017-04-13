#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char** argv) {

        char str[MAX_LENGTH];
        char temp[MAX_LENGTH];
        char* token;
        char* tokens[MAX_LENGTH];
        char* delim;

        printf("Write a command : ");

        fgets(str, MAX_LENGTH, stdin);
        strcpy(temp, str);

        token = strtok(temp,";");
        token = strtok(NULL,";"); //nao percebo bem o porque disto
        delim = ";";

        if(token == NULL)
                delim = "|";

        token = strtok(str,delim);

        int i = 0;
        while(token != NULL) {
                tokens[i] = token;
                token = strtok(NULL,delim);
                i++;
        }

        printf("\nDelim: %s\n", delim);
        printf("Tokens :\n");

        int j;
        for(j=0; j < i; j++) {
                printf("%s\n", tokens[j]);
        }
        exit(0);
}
