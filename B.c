#include <stdio.h>
#include <math.h>


enum
{
    MAX_PRECENTAGES = 100, //The maximum change absolute rate per day in percent.
    ROUND_CONST = 10000, //Constant of rounding the rate per day
    MAX_RATE = 10000 //limit of rate possible be per day
};

int
main(int argc, char *argv[]) 
{
    double rate;

    if (argc == 1) {
        return 1;
    }


    if (sscanf(argv[1], "%lf", &rate) != 1) {
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

        rate *= (MAX_PRECENTAGES + now) / MAX_PRECENTAGES;
   
        rate *= ROUND_CONST;

        rate = (double)round(rate) / ROUND_CONST;

        if (rate <= 0 && rate > MAX_RATE) {
            return 1;
        }
    }

    printf("%.4lf\n", rate);

    return 0;
}
