#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX 20

int main(void){
        struct termios term, oldterm;
        char pass[MAX+1], ch, echo = '*';

        write(STDOUT_FILENO, "\nInsert a password: ", 20); //escreve no fichiero da consola

        tcgetattr(STDIN_FILENO, &oldterm); //preenche termios
        term = oldterm;
        term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

        int i=0;
        //guarda pass e vai escrevendo no ficheiro da consola echo
        while (i < MAX && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
                pass[i++] = ch;
                write(STDOUT_FILENO, &echo, 1);
        }
        pass[i] = 0; //ultima posicao e sempre nula

        //o que vai ser escrito na consola
        tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
        write(STDOUT_FILENO, "\n\nYour password is: ", 20);
        write(STDOUT_FILENO, pass, strlen(pass));
        write(STDOUT_FILENO, "\n", 1);

        return 0;
}

/*
Escrevemos tudo no ficheiro da consola primeiro
temos que alterar o termos god knows why
enfim
*/
