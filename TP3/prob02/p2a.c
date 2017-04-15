// PROGRAMA p2.c

#include <stdio.h>
#include <sys/types.h> //necessario para a funcao fork
#include <unistd.h> //necessario para a funcao fork

int main(void) {
        write(STDOUT_FILENO,"1",1);
        if(fork() > 0) { //processo pai
                write(STDOUT_FILENO,"2",1);
                write(STDOUT_FILENO,"3",1);
        } else { //processo filho
                write(STDOUT_FILENO,"4",1);
                write(STDOUT_FILENO,"5",1);
        }
        write(STDOUT_FILENO,"\n",1);
        return 0;
}

/*
a) pode ser 12345, 14523, 12435, 12453 etc... (alterna os numeros)

b) aparece, sempre:
           123
           45
*/
