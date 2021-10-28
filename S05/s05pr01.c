//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

#define MAX 100

int main( int argc, char *argv[] )
{
    FILE *we = argc > 1 ? fopen( argv[1], "r" ) : stdin;
    int n = 0;
    double tab[MAX];

    if (we == stdin) {
        printf("Proszę wprowadzić kolejne liczby (maxymalnie %i):\n", MAX);
    }
    while (fscanf(we, "%lf", tab + n) == 1)
    {
        n++;
    }

    printf("Wprowadzone liczby to: \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%g \n", tab[i]);
    }
    return 0;
}