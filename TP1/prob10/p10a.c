#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char** argv) {

        char str[MAX_LENGTH];
        char* token;

        printf("Write a command : ");

        fgets(str, MAX_LENGTH, stdin);
        //stdin e o input recebido na consola
        //fgets passa o stdin para str

        token = strtok(str," ");
        //breaks string str into a series of tokens using the delimiter
        //https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

        printf("\nTokens :\n");

        while(token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL," ");
        }
        exit(0);
}
