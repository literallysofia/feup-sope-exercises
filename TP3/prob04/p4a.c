#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>

int main(void) {

        pid_t pid = fork();

        if (pid == -1) {
                perror("Fork ERROR ");
                exit(1);
        }

        if (pid != 0)
                printf("Hello ");
        else
                printf("world!\n");

        return 0;
}
