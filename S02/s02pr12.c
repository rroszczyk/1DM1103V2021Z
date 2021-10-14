//
// Created by Radosław Roszczyk on 12.10.2021.
// https://en.wikipedia.org/wiki/ANSI_escape_code
//
#include <stdio.h>

int main()
{
    int fg = 0;
    int i;

    for (i = 0; i <= 255; i++)
    {
        if (i <= 15)
        {
            fg = (i<=7)?15:0;
            printf("\x1B[38;5;%im\x1B[48;5;%im%6d     %s", fg, i, i, ((i+1)%4==0)?" ":"");
        } else if (i <= 231) {
            fg = (((i-16)%36)<=17)?15:0;
            printf("\x1B[38;5;%im\x1B[48;5;%im%4d ", fg, i, i);
        } else {
            fg = (i<=7)?15:0;
            printf("%s\x1B[38;5;%im\x1B[48;5;%im%5d  %s", ((i+1)%4==0)?" ":"", fg, i, i, ((i+1)%4==0)?" ":"");
        }
        if ((i - 15) % 36 == 0) printf("\x1B[0m\n");
    }
    printf("\x1B[0m\n");

    return 0;
}