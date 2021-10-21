//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

int main()
{
    int liczba = 100;

    int *ptr;

    ptr = &liczba;

    *ptr = 15;

    printf("liczba = %d\n", liczba);

    return 0;
}
