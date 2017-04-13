#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>

int main(int argc, char** argv) {

        if(argc != 3) {
                printf("not enough arguments!\n");
        } else {

                srand((unsigned) time(NULL)); //Intializes random number generator

                struct tms t;
                clock_t start, end, total;

                int n1 = (int)strtol(argv[1], NULL, 10);
                int n2 = (int)strtol(argv[2], NULL, 10);

                int num = 0;

                start = clock();

                while(num != n2) {
                        num = rand() % n1;
                        printf("%d\n", num);
                }

                end = clock();
                total = end - start;

                printf("Clock : %ld\n", total);
                printf("Time : %4.2f seconds\n", (double)(total / (double)CLOCKS_PER_SEC));
                printf("CPU user time : %4.2f seconds\n", (double)t.tms_cutime/ (double)CLOCKS_PER_SEC);
                printf("CPU system time : %4.2f seconds\n", (double)t.tms_cstime/ (double)CLOCKS_PER_SEC);

        }
        exit(0);
}
