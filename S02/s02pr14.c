//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

#ifndef maxymalna_liczba
#define maxymalna_liczba 50
#endif

int main()
{
    unsigned int liczby[maxymalna_liczba];
    unsigned int ile;
    unsigned int wynik = 0;

    printf("Ile liczb chcesz dodać - może to być maksymalnie %i:", maxymalna_liczba);
    scanf("%lu", &ile);
    for (int i = 0; i < ile; i++) {
        printf("Podaj liczbę do sumowania: ");
        scanf("%lu", &liczby[i]);
    }
    printf("Podałeś liczby: %lu", liczby[0]);
    for (int i = 1; i < ile; i++) {
        printf(", %lu", liczby[i]);
    }
    for (int i = 0; i < ile; i++) {
        wynik += liczby[i];
    }
    printf(" Obliczony wynik to: %lu", wynik);
    return 0;
}