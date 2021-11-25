//
// Created by roszczyr on 22.11.2021.
//
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* itobs(unsigned int a)
{
    unsigned int v = 1;

    size_t size = sizeof(a) << 3;  // sizeof(a) * 8
    v <<= size - 1;                // v = ((unsigned long int) ~ v + 1) >> 1;   // inicjalnie v = 0;

    size += sizeof("0b\0");
    char* s = calloc(size, sizeof(char));
    snprintf(s, size, "0b");

    int idx = strlen(s);
    for (unsigned int m = v; m > 0; m >>= 1)
    {
        s[idx++] = ((a & m) ? '1' : '0');
    }
    return s;
}

int main( )
{
    unsigned int x = 0;
    printf("%s\n", itobs(x));                    // wypisuje 0
    printf("%s\n", itobs(!x));                   // tutaj dokonujemy negacji zmiennej
    printf("%s\n", itobs(~x));                   // tutaj dokonujemy negacji bitów

    printf("0x%x \n", x);
    printf("0x%x \n", !x);
    printf("0x%x \n", ~x);

    unsigned int a = 0xf0f0f0f0;;
    unsigned int b = a;
    printf("   A: %s\n", itobs(a));
    printf("A>>2: %s\n", itobs(a>>2));
    printf("  !A: %s\n", itobs(!a));
    printf("  ~A: %s\n", itobs(~a));
    printf("A>>4: %s\n", itobs(a>>4^b));
    return 0;
}