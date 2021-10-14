//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    for (fahr = lower; fahr <= upper; fahr += step)
    {
        printf("%3.0f %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}
