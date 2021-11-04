//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

#define MAX 100

double sred (double v[], int n)
{
    double s= 0.0;
    for (int i = 0; i < n; i++)
    {
        s += v[i];
    }
    return s/n;
}

int main(int argc, char *argv[])
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

    printf("Srednia = %g\n", sred(tab, n));

    return 0;
}