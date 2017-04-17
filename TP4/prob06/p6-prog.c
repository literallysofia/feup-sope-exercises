#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void sigalarm_handler(int signo){

        printf("Alarme!\n");

        if (raise(SIGKILL) != 0)
                perror("Couldn't commit suicide : ");
}

int main(int argc, char* argv[]) {

        //argumentos passados pela funcao limit
        int limit = atoi(argv[0]);
        char* message = argv[1];

        signal(SIGALRM, sigalarm_handler); // instala alarme

        alarm(30); //quando passarem 30s, o handler e chamado

        for (int i = 0; i < limit; i++) {
                if (i % 5 == 0) printf("%s\n", message);
                sleep(1);
        }

        printf("%d seconds.\n", limit);
        exit(0);
}
