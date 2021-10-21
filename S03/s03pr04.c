//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("Program wypisujący wektor n liczb losowych z równomiernym prawdopodobieństwem z przedziału <początek, koniec> \n" );
        printf("Wywołany bez parametrów wypisuje wektor dla przedziału <0.0, 1.0> dzielony na 10");
        return 0;
    }

    double a = argc > 1 ? atof(argv[1]) : 0.0;
    double b = argc > 2 ? atof(argv[2]) : 1.0;
    int    n = argc > 3 ? atoi(argv[3]) : 10;

    double d;

    srand(time(NULL));
    //srand(100);

    d = a + (b - a) * (double)rand() / RAND_MAX;

    printf("[%f", d);
    for (int i = 1; i < n; i++ )
    {
        d = a + (b - a) * (double)rand() / RAND_MAX;
        printf( ", \t%f", d);
    }
    printf("]\n");

    return 0;
}

