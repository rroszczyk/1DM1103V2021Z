//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {
        celcius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%.2f\t%.2f\n", fahr, celcius);
        fahr = fahr + step;
    }

    return 0;
}
