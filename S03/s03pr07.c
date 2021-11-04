//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *we = argc > 1 ? fopen(argv[1],"r") : stdin;

    if (we != stdin) 
    {
        printf("Czytam dane z pliku\n");
    }

    if( we != NULL )
    {
        int n = 0;          // licznik liczb
        double x;           // wczytana liczba
        double min;         // najmniejsza liczba
        double max;         // największa liczba
        double sum = 0.0;   // suma

        while (fscanf(we, "%lf", &x ) == 1)
        {
            sum += x;
            if (n == 0 || x < min) min = x;
            if (n == 0 || x > max) max = x;
            n++;
        }

        printf("liczb było %d\n", n );
        if( n > 0 ) {
            printf("najmniejsza to %g\n", min );
            printf("największa to %g\n", max );
            printf("wartość średnia to %g\n", sum/n );
        }
        return EXIT_SUCCESS;
    } else {
        fprintf( stderr, "%s: nie mogę czytać %s\n", argv[0], ( argc > 1 ? argv[1] : "stdin" ) );
        return EXIT_FAILURE;
    }
}