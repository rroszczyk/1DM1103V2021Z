#include <stdio.h>

int main()
{
    char a[100];
    char b[100];

    int i;

    i = scanf("%s %s", &a, &b);

    printf("%s %s %d\n", a, b, i);
}