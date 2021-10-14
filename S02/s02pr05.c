//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {
        celcius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celcius);
        fahr = fahr + step;
    }

    return 0;
}
