//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;

    printf("Kody dziesiętne wielkich liter ASCII:\n");
    for (int i = 'A'; i <= 'Z'; i++)
        printf("%c - %d\n", i, i);
    printf("licznik: %d\n", i);
    return 0;
}
