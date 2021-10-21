//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "funkcja_przelicz.h"

#define DEFAULT_STEP 20

int main (int argc, char* argv[])
{
    int step = DEFAULT_STEP;

    if (argc >= 3)
    {
        int lower = atoi( argv[1]);
        int upper = atoi( argv[2]);

        if (argc == 4) {
            step = atoi(argv[3]);
        }
        
        if (step <= 0) {
            step = DEFAULT_STEP;
            printf("Wartość kroku powinna być większa od 0\n");
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
        return 0;
    } else {
        printf( "Proszę podać co najmniej dwa argumenty wywoałania programu \n");
        return 1;
    }
}