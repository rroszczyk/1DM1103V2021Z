//
// Created by Radosław Roszczyk on 12.10.2021.
// https://en.wikipedia.org/wiki/C_data_types
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    char c0 = 'd';
    char c1 = 100;
    signed char c2 = 0b01100100;
    unsigned char c3 = 0x64;

    printf("Rozmiar typu danych 'char': %lu\n", sizeof(c1));
    printf("Rozmiar typu danych 'signed char': %lu\n", sizeof(c2));
    printf("Rozmiar typu danych 'unsigned char': %lu\n", sizeof(c3));

    printf("Formatowanie %%c: %c, %c, %c, %c \n", c0, c1, c2, c3);
    printf("Formatowanie %%i: %i, %i, %i, %i \n", c0, c1, c2, c3);

    c1 = 127;
    c2 = 127;
    c3 = 127;

    printf("Liczba 127: %i, %i, %i \n", c1, c2, c3);

    c1 += 1;
    c2 += 1;
    c3 += 1;

    printf("Liczba 127+1: %i, %i, %i \n", c1, c2, c3);

    c1 = 0;
    c2 = 0;
    c3 = 0;

    printf("Liczba 0: %i, %i, %i \n", c1, c2, c3);

    c1 -= 1;
    c2 -= 1;
    c3 -= 1;

    printf("Liczba 0-1: %i, %i, %i \n", c1, c2, c3);
    return 0;
}

