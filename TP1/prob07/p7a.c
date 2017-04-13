#include <stdio.h>
#include <stdlib.h>

void handler0(void){
        printf("Executing exit handler 0\n");
}

void handler1(void){
        printf("Executing exit handler 1\n");
        //exit(0);
}

void handler2(void){
        printf("Executing exit handler 2\n");
}

int main(void) {
        atexit(handler0);
        atexit(handler1);
        atexit(handler2);
        //atexit(handler1);

        //abort();
        printf("Main done !\n");

        exit(0);
}
