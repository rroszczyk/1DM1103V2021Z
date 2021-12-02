//
// Created by Radosław Roszczyk on 01.12.2021.
// Hanoi
//
#include <stdio.h>

void towers(int num, char src, char dsc, char aux)
{
    if (num == 1)
    {
        printf("\n Przenieś dysk 1 z drążka %c na drążek %c", src, dsc);
        return;
    }
    towers(num - 1, src, aux, dsc);
    printf("\n Przenieś dysk %d z drążka %c na drążek %c", num, src, dsc);
    towers(num - 1, aux, dsc, src);
}

int main()
{
    int n = 2;

    towers(n, 'A', 'C', 'B');
    return 0;
}
