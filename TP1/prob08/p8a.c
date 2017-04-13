#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

        if(argc != 3) {
                printf("not enough arguments!\n");
        } else {

                srand((unsigned) time(NULL)); //Intializes random number generator

                int n1 = (int)strtol(argv[1], NULL, 10);
                int n2 = (int)strtol(argv[2], NULL, 10);

                int num = 0;

                while(num != n2) {
                        num = rand() % n1;
                        printf("%d\n", num);
                }
        }
        exit(0);
}
