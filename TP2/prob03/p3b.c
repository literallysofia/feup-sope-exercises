#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 256

int main(int argc, char** argv){

        if(argc > 3 || argc < 2)
                exit(1);
        else {
                char* file = argv[1];
                char buffer[MAX];

                //abrir ficheiro
                int df;
                df = open(file,O_RDONLY);

                if(argc == 3) {
                        char* otherFile = argv[2];
                        int dof;
                        dof = open(otherFile, O_RDONLY);
                        dup2(dof, df);
                }

                //copiar informacao
                int info;
                info=read(df, buffer,MAX);

                write(STDOUT_FILENO, "\nFile Content:\n", 15);
                write(STDOUT_FILENO, buffer, info);

                close (df);
        }
        return 0;
}
