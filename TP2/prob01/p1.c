#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define MAX 20

int main(void) {
        struct termios tms;

        tcgetattr(STDIN_FILENO, &tms); // Read the console's current definitions
        tms.c_lflag &= ~(ICANON | ECHO); //Activate raw mode
        tcsetattr(STDIN_FILENO, TCSANOW, &tms);

        write(STDOUT_FILENO, "Insert a password : ", 20);

        char* input = (char*)malloc(MAX);
        int index = 0;
        do {
                read(STDIN_FILENO, (input + index++), 1);
                write(STDOUT_FILENO, "*", 1);
        } while(input[index-1] != '\n');

        input[--index] = 0;

        printf("\nYour password is %s\n", input);
        return 0;
}


/*int main(void){
        struct termios term, oldterm;
        int i;
        char pass[MAX+1], ch, echo = '*';

        write(STDOUT_FILENO, "\nPassword? ", 11);

        tcgetattr(STDIN_FILENO, &oldterm);
        term = oldterm;
        term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

        i=0;
        while (i < MAX && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
                pass[i++] = ch;
                write(STDOUT_FILENO, &echo, 1);
        }
        pass[i] = 0;

        tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
        write(STDOUT_FILENO, "\n\nPassword: ", 12);
        write(STDOUT_FILENO, pass, strlen(pass));
        write(STDOUT_FILENO, "\n", 1);

        return 0;
}*/
