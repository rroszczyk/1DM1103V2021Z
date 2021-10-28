//
// Created by Radosław Roszczyk on 28.10.2021.
//
#include <stdio.h>

struct eax {
    int   a_1;      // 4 bajty
    int   a_2;      // 4 bajty
    char  c_1;      // 1 bajt
    int   a_3;      // 4 bajty
    char  c_2;      // 1 bajt
    char  c_3;      // 1 bajt
} EAX;

// structure A
typedef struct structa
{
    char        c;   // 1 bajt
    short int   s;   // 2 bajty
} structa_t;

// structure B
typedef struct structb
{
    short int   s;   // 2 bajty
    char        c;   // 1 bajt
    int         i;   // 4 bajty
} structb_t;

// structure C
typedef struct structc
{
    char        c;   // 1 bajt
    double      d;   // 8 bajty
    int         s;   // 4 bajt
} structc_t;

// structure D
typedef struct structd
{
    double      d;   // 8 bajty
    int         s;   // 4 bajty
    char        c;   // 1 bajt
} structd_t;

int main()
{
    printf("Rozmiar struktury danych: %d\n", sizeof(EAX));
    printf("Rozmiar struktury danych: %d\n", sizeof(structa_t));
    printf("Rozmiar struktury danych: %d\n", sizeof(structb_t));
    printf("Rozmiar struktury danych: %d\n", sizeof(structc_t));
    printf("Rozmiar struktury danych: %d\n", sizeof(structd_t));
}