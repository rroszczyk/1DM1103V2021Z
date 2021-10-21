//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

#define TABLESIZE(x) sizeof(x) / sizeof(x[0])

int main()
{
    int tbl[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19};

    printf("Liczba elementów tablicy: %d\n", TABLESIZE(tbl));

    return 0;
}