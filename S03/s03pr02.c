//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "funkcja_przelicz.h"

int main (int argc, char* argv[])
{
    int step = 20;
    int lower = 0;
    int upper = 0;

    if (argc >= 3) {
        lower = atoi(argv[1]);
        upper = atoi(argv[2]);

        if (argc == 4) {
            step = atoi(argv[3]);
        }
    }
    else if (argc > 1 && argc < 3)
    {
        printf( "Proszę podać co najmniej dwa argumenty wywołania programu \n");
        return 1;
    }
    else
    {
        printf("Podaj początkową temperaturę: ");
        scanf("%d", &lower);
        printf("Podaj końcową temperaturę: ");
        scanf("%d", &upper);
    }
    if (upper <= lower)
    {
        printf( "Koniec przedziału musi być większy od początku przedziału\n");
        return 1;
    }

    for (int fahr = lower; fahr <= upper; fahr += step)
    {
        printf("%d %6.2f\n", fahr, przelicz(fahr));
    }
}