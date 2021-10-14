//
// Created by roszczyr on 13.10.2021.
//
#include <stdio.h>
#include <float.h>

int main(int argc, char* argv[])
{
    float x = 0;

    for(int i = 1; i <= 10; i++) x += 0.1;

    if (x == 1)
    {
        printf("ok \n \n");
    }
    else
    {
        printf("błąd, wartość x to: %g \n\n", 1-x);
    }

    printf("%g", FLT_EPSILON);
}