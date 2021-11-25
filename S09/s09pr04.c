//
// Created by roszczyr on 22.11.2021.
//
#include <stdio.h>
#include <malloc.h>
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

struct stOp {
    unsigned char opcjaA;
    unsigned char opcjaB;
    unsigned char opcjaC;
    unsigned char opcjaD;
    unsigned char opcjaE;
    unsigned char opcjaF;
    unsigned char opcjaG;
    unsigned char opcjaH;
} sOp;

struct stOpcje {
    unsigned char opcjaA : 1;
    unsigned char opcjaB : 1;
    unsigned char opcjaC : 1;
    unsigned char opcjaD : 1;
    unsigned char opcjaE : 1;
    unsigned char opcjaF : 1;
    unsigned char opcjaG : 1;
    unsigned char opcjaH : 1;
} sOpcje;

union unKonfig {
    unsigned char Params;
    struct stOpcje Opcje;
} sKonfig;

int main( )
{
    union unKonfig Konfig = {0};

    printf("Rozmiar struktury stOp: %d \n", sizeof(sOp));
    printf("Rozmiar struktury stOppcje: %d \n", sizeof(sOpcje));
    printf("Rozmiar uni unKonfig: %d \n", sizeof(sKonfig));

    printf("%s \n", itobs(Konfig.Params));

    Konfig.Opcje.opcjaA = 1;
    Konfig.Opcje.opcjaB = 1;
    Konfig.Opcje.opcjaG = 1;
    Konfig.Opcje.opcjaH = 1;

    printf("%s \n", itobs(Konfig.Params));

    return 0;
}