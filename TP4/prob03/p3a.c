#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static int var = 0;

void sigusr_handler(int signo) {

        if(signo == SIGUSR1)
                var++;

        if(signo == SIGUSR2)
                var--;

        sleep(1);
}

int main(void) {

        struct sigaction action;
        action.sa_handler = sigusr_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;

        if (sigaction(SIGUSR1,&action,NULL) < 0) {
                fprintf(stderr,"Unable to install SIGUSR handler\n");
                exit(1);
        }

        if (sigaction(SIGUSR2,&action,NULL) < 0) {
                fprintf(stderr,"Unable to install SIGUSR handler\n");
                exit(1);
        }

        while(1) {
                printf("variable : %d\n", var);
                pause();
        }

        exit(0);
}
