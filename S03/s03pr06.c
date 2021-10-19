//
// Created by Radosław Roszczyk on 19.10.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *we = argc > 1 ? fopen(argv[1],"r") : stdin;
    FILE *wy = argc > 2 ? fopen(argv[2],"w") : stdout;

    if( we != NULL )
    {
        int nc = 0;
        int nl = 0;
        int nd = 0;
        int c;
        while ((c = fgetc(we)) != EOF)
        {
            nc++;
            if (c == '\n')
                nl++;
            if (c >= '0' && c <= '9')
                nd++;
        }

        fprintf( wy, "%d znaków, %d cyfr dziesiętnych, %d linii w %s\n", nc, nd, nl, ( argc > 1 ? argv[1] : "stdin" ) );
        return EXIT_SUCCESS;
    } else {
        fprintf( stderr, "%s: nie mogę czytać %s\n", argv[0], ( argc > 1 ? argv[1] : "stdin" ) );
        return EXIT_FAILURE;
    }
}