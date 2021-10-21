//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

int main()
{
    int ti[] = {1, 2, 3, 4, 5};

    int *ptr;

    ptr = ti;

    printf("rozmiar pamięci zajmowany przez tablicę: %d, rozmiar pamięci zajmowany przez komórkę: %d \n", sizeof(ti), sizeof(ti[0]));
    for (int i = 0; i < sizeof(ti) / sizeof(ti[0]); ++i)
    {
        printf("%d \t", ti[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(ti) / sizeof(ti[0]); ++i, ++ptr)
    {
        printf("%d \t", *ptr);
    }
    printf("\n");

    ptr = ti;
    for (int i = 0; i < sizeof(ti) / sizeof(ti[0]); ++i, ++ptr)
    {
        printf("%p -> %d \n", ptr, *ptr);
    }

    return 0;
}