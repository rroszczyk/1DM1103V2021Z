//
// Created by Radosław Roszczyk on 01.12.2021.
// Quick Sort Rekurencja
//
#include <stdio.h>
#include <stdbool.h>

int sumaIterative(int n)
{
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int sumaRecursive(int n)
{
    if (n < 1) {
        return 0;
    }
    return n + sumaRecursive(n - 1);
}

int main()
{
    int n = 10;
    int si = sumaIterative(n);
    int sr = sumaRecursive(n);

    printf("Suma kolejnych %d liczb naturalnych wynosi: %d\n", n, si);
    printf("Suma kolejnych %d liczb naturalnych wynosi: %d\n", n, sr);

    return 0;
}
