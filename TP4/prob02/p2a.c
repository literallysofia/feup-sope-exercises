#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
        printf("Entering SIGINT handler ...\n");
        sleep(10);
        printf("Exiting SIGINT handler ...\n");
}

int main(void) {

        struct sigaction action;
        action.sa_handler = sigint_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;

        if (sigaction(SIGINT,&action,NULL) < 0) {
                fprintf(stderr,"Unable to install SIGINT handler\n");
                exit(1);
        }

        printf("Try me with CTRL-C ...\n");

        while(1) pause();

        exit(0);
}

/*
a)
Assim que e carregado CTRL-C entra no handler, e devido ao sleep(10)
se carregarmos novamente, nao ira ser processado.
Temos que esperar que o sleep acabe, e saia do handler.
AKA enquanto esta no handler e a dormir nao podem ser processados mais
sinais, apenas fora deste. ;)

b)
Abrir nova janela da terminal enquanto este programa corre noutra.
Usar comando: ps -u
Apartir dele conseguimos ver o pid do programa que esta a correr
Usar comando: kill -SIGTERM pid
Tada, programa acaba.
*/
