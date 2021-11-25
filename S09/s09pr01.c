//
// Created by roszczyr on 22.11.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void itob(unsigned int a)
{
    unsigned int v = 0;

    for (unsigned long int m = ((unsigned long int)~v + 1)>>1; m > 0; m >>= 1)
    {
        printf("%s", ((a & m) ? "1" : "0"));
    }
    printf("\n");
}

int main( )
{
    srand( time( NULL ));
    unsigned int x = rand( );

    itob(x);
    itob(~x); // tutaj dokonujemy negacji bitów
    return 0;
}