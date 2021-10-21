//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

int* wynikOperacji(int a, int b)
{
    int wynik = a + b;

    return &wynik;
}

int main()
{
    int a = 100;
    int b = 50;

    int* wynik = wynikOperacji(a, b);

    printf("a + b = %d\n", a + b);
    printf("a + b = %d\n", *wynik);

    return 0;
}