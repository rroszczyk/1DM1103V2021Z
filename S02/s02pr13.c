//
// Created by Radosław Roszczyk on 12.10.2021.
//
#include <stdio.h>

int main()
{
    for (int i=0;i<=255;i++)
        if (i<=15) printf("\x1B[38;5;%im\x1B[48;5;%im%6d     %s%s",i<=7?15:0,i,i,(i+1)%4==0?" ":"",(i-15)%36==0?"\x1B[0m\n":"");
        else if (i<=231) printf("\x1B[38;5;%im\x1B[48;5;%im%4d %s",(i-16)%36<=17?15:0,i,i,(i-15)%36==0?"\x1B[0m\n":"");
        else printf("%s\x1B[38;5;%im\x1B[48;5;%im%5d  %s%s",(i+1)%4==0?" ":"",(i-16)%36<=11?15:0,i,i,(i+1)%4==0?" ":"",(i-15)%36==0?"\x1B[0m\n":"");
    printf("\x1B[0m\n");
    return 0;
}