#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 256

int main(int argc, char** argv){

        if(argc != 2)
                exit(1);
        else {
                char* file = argv[1];
                char buffer[MAX];

                //abrir ficheiro
                int df;
                df = open(file,O_RDONLY);

                //copiar informacao
                int info;
                info=read(df, buffer,MAX);

                write(STDOUT_FILENO, "\nFile Content:\n", 15);
                write(STDOUT_FILENO, buffer, info);

                close (df);
        }
        return 0;
}

// versao convencional e simples

/*int main(int argc, char** argv){

        if(argc != 2)
                exit(1);
        else {
                FILE* file;
                char line[MAX];

                if( (file = fopen(argv[1], "r")) == NULL)
                        exit(2);

                printf("\nFile Content:\n");

                while( (fgets(line, MAX, file)) != NULL)
                        printf("%s", line);

                fclose(file);
        }
        return 0;
   }*/
