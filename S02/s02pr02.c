//
// Created by Radosław Roszczyk on 12.10.2021.
// https://en.wikipedia.org/wiki/C_data_types
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    short s;
    int i;
    long l;

    printf("Rozmiar typu danych 'short': %lu\n", sizeof(s));
    printf("Rozmiar typu danych 'int': %lu\n", sizeof(i));
    printf("Rozmiar typu danych 'long': %lu\n", sizeof(l));
    return 0;
}
