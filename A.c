#include <stdio.h>


int
main(int argc, char *argv[])
{
    int negative_n = 0;
    int positive_n = 0;


    for (int i = 1; i < argc; i++) { 
       int now;

       if (sscanf(argv[i], "%d", &now) != 1) {
           return 1;
       }

       if (now < 0) {
           negative_n += now;
       } else {
           positive_n += now;
       }
    }

    printf("%d\n%d\n", positive_n, negative_n);

    return 0;
}
