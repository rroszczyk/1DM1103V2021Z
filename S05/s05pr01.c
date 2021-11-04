//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

#define MAX 100

int main(int argc, char *argv[])
{
    FILE *we = argc > 1 ? fopen( argv[1], "r" ) : stdin;
    int n = 0;
    double tab[MAX];
    double suma = 0.0;
    double min = __DBL_NORM_MAX__;
    double max = __DBL_MIN__;
    int minP, maxP;

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

    for (int i = 0; i < n; ++i) 
    {
        suma += tab[i];
        if (tab[i] <= min) {
            min = tab[i];
            minP = i;
        }
        if (tab[i] >= max) {
            max = tab[i];
            maxP = i;
        }
    }
    printf("Wprowadziłeś %d liczb\n", n);
    printf("Średnia wartość to %g\n", suma/n);
    printf("Wartość minimalna to: %g i jest to %d liczba\n", min, minP);
    printf("Wartość maksymalna to: %g i jest to %d liczba\n", max, maxP);
    return 0;
}