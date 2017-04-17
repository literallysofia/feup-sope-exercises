#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

        if (argc != 4) {
                printf("Wrong no of arguments.\n");
                exit(1);
        }

        if (execl(argv[2], argv[1], argv[3], NULL) == -1)
                perror("Error ");
}
