//
// Created by Radosław Roszczyk on 20.10.2021.
//
#include <stdio.h>
#include <malloc.h>

int czyJestNaStosie(void* ptr)
{
    int dummy; // zawsze umieszczone jest na stosie
    return ptr > (void*)&dummy;
}

int a = 100;
int b;
int c = 101;

int main(int argc, char** argv)
{
    int tbl[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void *ptr = malloc(sizeof(int));

    int i = 100;
    int j;

    if (argc < 1) return 1;

    printf("argumenty wywołania programu %s, %s \n", argv[0], argv[1]);
    printf("czy argumenty wywołania programu są na stosie? argc: %d, argv %d, argv[0] %d\n", czyJestNaStosie(&argc), czyJestNaStosie(*argv), czyJestNaStosie(&argv[0][0]));

    //printf("argumenty wywołania programu ptr: %d, i: %d, argc: %d \n", czyJestNaStosie(ptr), czyJestNaStosie(&i), czyJestNaStosie(&argc));

    printf("Adres licznika argc: %p\n", &argc);
    printf("Adres parametrów argv : %p\n", *argv);
    printf("Adres pierwszego parametru: %p\n", &argv[0][0]);
    printf("\n");
    printf("Adres 1 elementu umieszczonego na stosie lokalnym %p\n", &ptr);
    printf("Adres 2 elementu umieszczonego na stosie lokalnym %p\n", &i);
    printf("Adres 3 elementu umieszczonego na stosie lokalnym %p\n", &j);
    printf("\n");
    printf("Adres elementu umieszczonego na stercie %p\n", ptr);
    printf("\n");
    printf("Czy zainicjowana tablica jest na stosie? %d\n", czyJestNaStosie(&tbl));
    printf("\n");
    printf("Adres i rozmiar zanicjiowanego globalnego elementu a %p -> %d\n", &a, sizeof(a));
    printf("Adres i rozmiar niezanicjiowanego globalnego elementu b %p -> %d\n", &b, sizeof(b));
    printf("Adres i rozmiar zanicjiowanego globalnego elementu c %p -> %d\n", &c, sizeof(c));
    free(ptr);

    return 0;
}