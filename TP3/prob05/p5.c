#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

        pid_t pid = fork();

        if (pid == -1) {
                perror("Fork ERROR ");
                exit(1);
        }

        if (pid != 0)
                printf("Hello ");
        else {
                pid_t pid2 = fork();

                if (pid2 != 0)
                        printf("my ");
                else
                        printf("friends!\n");

        }

        return 0;
}
