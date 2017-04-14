#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

int main(void) {
        int fd;
        char *text1="AAAAA";
        char *text2="BBBBB";
        fd = open("f1.txt",O_CREAT|O_WRONLY|O_SYNC|O_APPEND,0600);

        if(fd == -1) {
                perror("Error ");
                return -1;
        }

        write(STDOUT_FILENO, "Writing AAAAA on file. Press a key to continue.", 47);

        getchar();
        write(fd,text1,5);

        write(STDOUT_FILENO, "Writing BBBBB on file. Press a key to continue.", 47);

        getchar();
        write(fd,text2,5);

        close(fd);
        return 0;
}
