#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(void) {

        pid_t pid;
        int i, n, status;

        if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) { //Silently reap children.
                perror("Unable to install SIGCHLD handler\n");
                exit(1);
        }

        for (i=1; i<=10; i++) {
                pid=fork();
                if (pid == 0) {
                        printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());
                        sleep(15); // child working ...
                        printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());
                        exit(0);
                }
        }

        for (i=1; i<=4; i++ ) {
                printf("PARENT: working hard (task no. %d) ...\n",i);
                n=4; while((n=sleep(n))!=0) ;
                printf("PARENT: end of task no. %d\n",i);
                printf("PARENT: waiting for child no. %d ...\n",i);

                if (pid != -1)
                        printf("PARENT: child with PID=%d terminated with exit code %d\n",pid,WEXITSTATUS(status));
        }

        exit(0);
}

/*
O que era para fazer aqui mesmo?
*/
