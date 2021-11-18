//
// Created by Radosław Roszczyk on 10.11.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "sb.h"
int main(void)
{
    // create an empty string builder
    StringBuilder *sb = sbCreate();
    char *str = NULL;

    // append some strings
    sbAppendf(sb, "What is your name?\n -> %s\n\n", "Sir Lancelot, of Camelot");
    sbAppendf(sb, "What is your quest?\n -> %s\n\n", "To seek the Holy Grail");
    sbAppendf(sb, "What is your favorite color?\n -> %s\n\n", "Blue");
    sbAppend(sb, "Right, off you go");

    // print
    str = sbConcat(sb);
    puts(str);

    // clean up
    free(str);
    sbFree(sb);
    return 0;
}
