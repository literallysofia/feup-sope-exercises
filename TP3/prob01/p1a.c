// PROGRAMA p1.c

#include <stdio.h>
#include <sys/types.h> //necessario para a funcao fork
#include <unistd.h> //necessario para a funcao fork

int global = 1;

int main(void) {
        int local = 2;
        if(fork() > 0) {
                printf("PID = %d; PPID = %d\n", getpid(), getppid());
                global++;
                local--;
        } else {
                printf("PID = %d; PPID = %d\n", getpid(), getppid());
                global--;
                local++;
        }
        printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
        return 0;
}

/*
a) o fork retorna o PID do processo do filho, caso este esteja a decorrer, caso já
tenha acabado, retorna 0.
getpid -> retorna PID do processo filho
getppid -> retorna PID do processo pai
b) PID aumenta, PPID mantem-se sempre constante
*/
