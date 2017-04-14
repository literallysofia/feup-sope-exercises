#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define MAX 256
#define DST_FILE "output.txt"

int main(int argc, char** argv) {

        int DST_FILENO = open(DST_FILE, (O_WRONLY | O_CREAT | O_SYNC | O_EXCL), (S_IRUSR | S_IWUSR | S_IXUSR));

        if(DST_FILENO == -1) {
                perror("Error opening file ");
                exit(-1);
        }

        write(STDOUT_FILENO, "STUDENTS INFORMATION\nPress CTRL+C to finish.\n", 46);
        char* input[MAX];
        char* number[MAX];
        int info;

        do {
                write(STDOUT_FILENO, "Insert a student's name : ", 26);
                info = read(STDIN_FILENO, input, MAX);
                write(DST_FILENO, input, info);
                write(STDOUT_FILENO, "Insert a student's grade : ", 27);
                info = read(STDIN_FILENO, number, MAX);
                write(DST_FILENO, number, info);
        } while(1); //CTRL+C para terminar

        close(DST_FILENO);
        return 0;
}

/*
cat output.txt
- display do ficheiro
*/
