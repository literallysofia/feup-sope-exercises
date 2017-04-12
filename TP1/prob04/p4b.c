#include <stdio.h>

int main(int argc, char* argv[])
{

  if(argc != 1){
    int counter = atoi(argv[1]);

    while(counter > 0){
      printf("Hello %s!\n", argv[2]);
    }

  }
  else {
    printf("Too many or few arguments!\n");
  }

  return 0;
}
