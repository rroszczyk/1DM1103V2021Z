//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("Program wypisujący wektor liczb zaczynający się od wartości pierwszego argumentu do wartości drugiego podzielony na liczbę przedziałów z trzeciego.\n" );
        printf("Wywołany bez parametrów wypisuje wektor zaczynający się od 0.0 do 1.0 dzielony na 10");
        return 0;
    }

    double a = argc > 1 ? atof(argv[1]) : 0.0;
    double b = argc > 2 ? atof(argv[2]) : 1.0;
    int    n = argc > 3 ? atoi(argv[3]) : 10;

    double d = (b-a) / (n-1);

    printf("[%f", a);
    for (int i = 1; i < n; i++ )
        printf( ", \t%f", a+i*d );
    printf("]\n");

    return 0;
}

