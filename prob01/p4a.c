#include <stdio.h>

int main(int argc, char* argv[])
{
  int i = 1;

  printf("Hello");

  while(argv[i] != NULL){
    printf(" %s", argv[i]);
    i++;
  }

  printf("!\n");
  return 0;
}
