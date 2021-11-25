//
// Created by roszczyr on 22.11.2021.
//
#include <stdio.h>

struct stPunkt {
    double x;
    double y;
    double z;
};

union unPunkt {
    double x;
    double y;
    double z;
};

int main( )
{
    struct stPunkt stP;
    union unPunkt unP;

    printf("Rozmiar struktury stPunkt: %d \n", sizeof(stP));
    printf("Rozmiar uni unPunkt: %d \n", sizeof(unP));

    return 0;
}