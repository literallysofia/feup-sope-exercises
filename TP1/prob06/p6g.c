#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_LENGTH 256

int main(int argc, char** argv) {

        FILE *src, *dst;
        char buf[BUF_LENGTH];
        char* srcFile = argv[1];
        char* dstFile = argv[2];

        if ( ( src = fopen( srcFile, "r" ) ) == NULL ) {
                printf("%d\n", errno);
                exit(1); //programa acaba aqui
        }

        if ( ( dst = fopen( dstFile, "w" ) ) == NULL ) {
                printf("%d\n", errno);
                exit(2);
        }
        while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ) {
                fputs( buf, dst );
        }

        fclose( src );
        fclose( dst );
        exit(0); // zero é geralmente indicativo de "sucesso"
}
