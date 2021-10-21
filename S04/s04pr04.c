//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>

int main()
{
    int dd[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    int *ptr = (int*)&dd;

    printf("Rozmiar tablicy %d\n", sizeof(dd));
    printf("Rozmiar elementu tablicy %d\n", sizeof(dd[0]));
    printf("Rozmiar komórki tablicy %d\n", sizeof(dd[0][0]));
    printf("\n");
    printf("Liczba elementów tablicy %d\n", sizeof(dd) / sizeof(dd[0]));
    printf("Liczba komórek w elemencie tablicy %d\n", sizeof(dd[0]) / sizeof(dd[0][0]));
    printf("Liczba komórek w tablicy %d\n", sizeof(dd) / sizeof(dd[0][0]));

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d\t", dd[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < 4 * 3; i++, ptr++)
    {
        printf("%d\t", *ptr);
    }
    printf("\n");

    return 0;
}
