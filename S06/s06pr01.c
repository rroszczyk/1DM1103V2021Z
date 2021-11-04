//
// Created by Radosław Roszczyk on 03.11.2021.
//
#include<stdio.h>
#include<stdlib.h>

void printInt(void *n)
{
    printf(" %d", *(int*)n);
}

void printFloat(void *f)
{
    printf(" %g", *(float *)f);
}

void printVariable(void *var, void (*handle)(void *))
{
    (*handle)(var);
}

int main()
{
    int I = 100;
    float F = 12.34;

    printVariable(&I, printInt);
    printVariable(&F, printFloat);

    return 0;
}