//
// Created by Radosław Roszczyk on 28.10.2021.
//
#include <stdio.h>
#include <math.h> // -lm

struct punkt {
    double x;
    double y;
    double z;
};

void wczytajPunkt(char *s, struct punkt *p)
{
    double tmp;
    printf("Podaj współrzędną X %s punktu: ", s);
    scanf("%lf", &tmp);
    (*p).x = tmp;

    printf("Podaj współrzędną Y %s punktu: ", s);
    scanf("%lf", &tmp);
    p->y = tmp;

    printf("Podaj współrzędną Z %s punktu: " s);
    scanf("%lf", &(*p).z);
}

void wypiszPunkt(char *s, struct punkt *p)
{
    printf("%s: (%g, %g, %g)\t", s, p->x, p->y, p->z);
}

double obliczDlugoscWektora(struct punkt *a, struct punkt *b)
{
    double x = pow((a->x - b->x) , 2);
    double y = pow((a->x - b->x) , 2);
    double z = pow((a->x - b->x) , 2);
    return (sqrt(x + y + z));
}

int main()
{
    struct punkt A = {0, 0, 0};
    struct punkt B;
    double odleglosc;

    wczytajPunkt("pierwszego", &A);
    wczytajPunkt("drugiego", &B);
    wypiszPunkt("A", &A);
    wypiszPunkt("B", &B);
    printf("\n");
}