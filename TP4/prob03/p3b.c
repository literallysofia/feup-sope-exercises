#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

static int var = 0;

void sigusr_handler(int signo) {

        if(signo == SIGUSR1)
                var++;

        if(signo == SIGUSR2)
                var--;
}

int main(void) {

        if (signal(SIGUSR1,sigusr_handler) == SIG_ERR) {
                fprintf(stderr,"Unable to install SIGUSR handler\n");
                exit(1);
        }

        if (signal(SIGUSR2,sigusr_handler) == SIG_ERR) {
                fprintf(stderr,"Unable to install SIGUSR handler\n");
                exit(1);
        }

        int counter = 0;
        srand(time(NULL));
        pid_t pid = fork();

        while (counter < 50) {

                if(pid == -1)
                        perror("Fork ");
                else if (pid != 0) {
                        int i = rand() % 2;

                        if(i == 0)
                                kill(pid, SIGUSR1);
                        else
                                kill(pid, SIGUSR2);
                        sleep(1);
                } else {
                        printf("variable : %d\n", var);
                        counter++;
                        sleep(1);
                }
        }

        return 0;
}
