//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;

    printf("Kody dziesiętne wielkich liter ASCII:\n");
    for (i = 'A'; i <= 'Z'; i++)
        printf("%c - %d\n", i, i);
    return 0;
}
