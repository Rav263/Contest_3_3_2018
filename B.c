#include <stdio.h>

int
main(int argc, char *argv[]) 
{
    double course;

    if (argc == 1) {
        return 1;
    }

    
    if (sscanf(argv[1], "%lf", &course) != 1) {
        return 1;
    }


    for (int i = 2; i < argc; i++){
        double now;

        if (sscanf(argv[i], "%lf", &now) != 1) {
            return 1;
        }

        if (now <= -100 || now >= 100) {
            return 1;
        }

        course *= (100 + now) / 100;
    }

    printf("%.4lf\n", course);

    return 0;
}
