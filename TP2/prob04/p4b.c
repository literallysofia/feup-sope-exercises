#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define MAX 50
#define DST_FILE "outputb.txt"

struct Student {
        char* name[MAX];
        int* grade;
};

int main(int argc, char** argv) {

        int DST_FILENO = open(DST_FILE, (O_WRONLY | O_CREAT | O_SYNC | O_EXCL), (S_IRUSR | S_IWUSR | S_IXUSR));

        if(DST_FILENO == -1) {
                perror("Error opening file ");
                exit(-1);
        }

        write(STDOUT_FILENO, "STUDENTS INFORMATION\nPress CTRL+C to finish.\n", 46);

        int counter = 0;
        do {
                struct Student st;
                write(STDOUT_FILENO, "Insert a student's name : ", 26);
                read(STDIN_FILENO, st.name, MAX);

                write(STDOUT_FILENO, "Insert a student's grade : ", 27);
                read(STDIN_FILENO, st.grade, MAX);

                write(DST_FILENO, &st, sizeof(struct Student));
                counter++;

        } while (counter < 2);

        close(DST_FILENO);

        printf("\nFILE CONTENT:\n\n");

        FILE* file;

        if((file = fopen(DST_FILE,"rb")) == NULL)
                exit(-1);

        struct Student st;
        int i;
        for(i = 0; i < counter; i++) {
                fread(&st, sizeof(struct Student), 1, file);
                printf("%s %d\n", st.name, st.grade);
        }
        return 0;
}
