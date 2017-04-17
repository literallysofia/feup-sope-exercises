#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
        printf("In SIGINT handler ...\n");
}

int main(void) {

        struct sigaction act;
        act.sa_handler = sigint_handler; //chamada a funcao handler
        sigemptyset(&act.sa_mask); //sinais bloqueados vazios na execucao do handler
        act.sa_flags = 0; //nenhuma nova modificacao

        if (sigaction(SIGINT, &act, NULL) < 0) {
                fprintf(stderr,"Unable to install SIGINT handler\n");
                exit(1);
        }

        printf("Sleeping for 30 seconds ...\n");

        int timer = sleep(30);

        while (timer != 0) { // quando sleep retorna 0, e quando acaba
                timer = sleep(timer);
        }

        printf("Waking up ...\n");
        exit(0);
}
