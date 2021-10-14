//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 20

int main(int argc, char* argv[])
{
    float fahr;


    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3.0f %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}
