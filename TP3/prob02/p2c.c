// PROGRAMA p2.c

#include <stdio.h>
#include <sys/types.h> //necessario para a funcao fork
#include <unistd.h> //necessario para a funcao fork

int main(void) {
        printf("1");
        //printf("1\n");
        if(fork() > 0) {
                printf("2");
                printf("3");
        } else {
                printf("4");
                printf("5");
        }
        printf("\n");
        return 0;
}

/*
c)
      aparece:
           123
           145

d)
      aparece:
            1
            23
            45
 */
