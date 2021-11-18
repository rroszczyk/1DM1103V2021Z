//
// Created by Radosław Roszczyk on 10.11.2021.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    char haslo_poprawne = 0;
    char haslo[16];

    if (argc != 2)
    {
        printf("uzycie: %s haslo\nx", argv[0]);
        return EXIT_FAILURE;
    }
    // 11111111111111111111111111111111
    strcpy(haslo, argv[1]);

    if (!strcmp(haslo, "poprawne")) {       // nadpisanie hasła poprawnego tą samą zawartością co było w argumencie
        haslo_poprawne = 1;
    }

    if (!haslo_poprawne) {
        printf("Podales bledne haslo.\n");
        return EXIT_FAILURE;
    }

    printf("Witaj, wprowadziles poprawne haslo. \n");
    return EXIT_SUCCESS;
}
