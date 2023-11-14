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

    if (argc != 2) {
        printf("uzycie: %s haslo", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(haslo, argv[1], sizeof haslo - 1);
    haslo[sizeof haslo - 1] = 0;

    if (!strcmp(haslo, "poprawne")) {
        haslo_poprawne = 1;
    }
    if (!haslo_poprawne) {
        printf("Podales bledne haslo.\n");
        return EXIT_FAILURE;
    }

    printf("Witaj, wprowadziles poprawne haslo.\n");
    return EXIT_SUCCESS;
}