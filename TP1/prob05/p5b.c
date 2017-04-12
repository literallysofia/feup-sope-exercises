#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
        int i = 0;
        char str[5]= "USER=";

        while(envp[i] != NULL) {

                if(strncmp(envp[i],str,5) == 0) {
                        printf("Hello %s!\n", envp[i]+5);
                        break;
                }
                i++;
        }
        return 0;
}
