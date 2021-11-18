//
// Created by Radosław Roszczyk on 10.11.2021.
//
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[10], str2[10];
    int cmp;

    printf("Wprowadź pierwszy ciąg znaków:");
    scanf("%s", &str1);
    printf("Wprowadź drugi ciąg znaków:");
    scanf("%s", &str2);

    cmp = strlen(str1) - strlen(str2);
    if (cmp < 0) {
        printf("Pierwszy napis jest krótszy od drugiego. ");
    } else if (cmp > 0) {
        printf("Pierwszy napis jest dłuższy od drugiego. ");
    } else {
        printf("Obydwa napisy są tej samej długości. ");
    }

    cmp = strcmp(str1, str2);
    if (cmp < 0) {
        printf("Pierwszy napis wystąpi pierwszy w słowniku\n");
    } else if (cmp > 0) {
        printf("Drugi napis wystąpi pierwszy w słowniku.\n");
    } else {
        printf("I są dokładnie identyczne. \n");
    }
    return 0;
}
