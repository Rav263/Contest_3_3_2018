#include <stdio.h>
#include <math.h>


enum
{
    MAX_PRECENTAGES = 100, //max precentages value of variation of rate
    ROUND_CONST = 10000, //Rounding constat of rate every day
    MAX_COURSE = 10000 //max rate that may be in a problem
};

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
        if (now <= -MAX_PRECENTAGES || now >= MAX_PRECENTAGES) {
            return 1;
        }

        course *= (MAX_PRECENTAGES + now) / MAX_PRECENTAGES;
   
        course *= ROUND_CONST;

        course = (double)round(course) / ROUND_CONST;

        if (course <= 0 && course > MAX_COURSE) {
            return 1;
        }
    }

    printf("%.4lf\n", course);

    return 0;
}
