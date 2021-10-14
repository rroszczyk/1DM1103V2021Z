//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>
#include "colors.h"

int main(int argc, char* argv[])
{
    printf(FRED("Czerwony napis\n"));
    printf(UNDL(FGRN("Zielony napis\n")));
    printf(BOLD(FYEL("Żółty napis\n")));
    printf(FBLU("Niebieski napis\n"));
    printf(FMAG("Magentowy napis\n"));
    printf(FCYN("Błękitny napis\n"));
    printf(FWHT("Biały napis\n"));
    return 0;
}

