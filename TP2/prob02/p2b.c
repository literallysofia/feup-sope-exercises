#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

#define MAX 15

int main(int argc, char** argv){

        if(argc != 3)
                exit(1);
        else {
                char* src = argv[1];
                char* dst = argv[2];
                char buffer[MAX];

                //abrir ficheiros
                int dfs,dfd;
                dfs=open(src,O_RDONLY);
                dfd=open(dst, O_WRONLY);

                //copiar informacao
                int info;
                info=read(dfs, buffer,MAX);
                write(dfd,buffer,info);

                close (dfs);
                close (dfd);

                printf("Success!\n");
        }
        return 0;
}
