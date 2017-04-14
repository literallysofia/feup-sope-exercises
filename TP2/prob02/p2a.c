#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

//copy source des

int main(int argc, char** argv){

        if(argc != 3)
                exit(1);
        else {
                FILE* src;
                FILE* dst;
                char buffer[MAX];

                if( (src = fopen(argv[1], "r")) == NULL)
                        exit(2);

                if( (dst = fopen(argv[2], "w")) == NULL)
                        exit(3);

                fread(buffer, sizeof(char), MAX, src);
                fwrite(buffer, sizeof(char), MAX, dst);

                fclose(src);
                fclose(dst);

                printf("Success!\n");
        }
        return 0;
}
