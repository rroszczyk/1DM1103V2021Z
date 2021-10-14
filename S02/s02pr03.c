//
// Created by Radosław Roszczyk on 12.10.2021.
// https://en.wikipedia.org/wiki/C_data_types
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    float f;
    double d;
    long double ld;

    printf("Rozmiar typu danych 'float': %lu\n", sizeof(f));
    printf("Rozmiar typu danych 'double': %lu\n", sizeof(d));
    printf("Rozmiar typu danych 'long double': %lu\n", sizeof(ld));
    return 0;
}
