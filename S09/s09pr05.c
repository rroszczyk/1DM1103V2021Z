//
// Created by roszczyr on 22.11.2021.
//
#include <stdio.h>
#include <malloc.h>

#define KONIEC  0
#define tPusty  0
#define tID     1
#define tImie   2

struct stUser {
    int type;
    union uUser {
        int id;
        char imie[20];
    } user;
    char mail[80];
} sfUser;

void printUser(struct stUser* u)
{
    if (u != NULL) {
        switch (u->type) {
            case tID: {
                printf("Użytkownik id: %i", u->user.id);
                break;
            }
            case tImie: {
                printf("Użytkownik o imieniu: %s", u->user.imie);
                break;
            }
        }
        printf(" posiada adres mailowy %s\n", u->mail);
    }
}

struct stUser* readUser(struct stUser* u)
{
    if ((u != NULL) && (u->type == tPusty)) {
        printf("Wybierz co chcesz wprowadzić:\n");
        printf("1 - identyfikator,\n2 - imię\ndowolny inny znak przerywa wczytywanie\n: ");
        scanf("%i", &u->type);
        switch (u->type) {
            case tID: {
                printf("Wprowadź identyfikator użytkownika: ");
                scanf("%i", &u->user);
                u->type = tID;
                break;
            }
            case tImie: {
                printf("Wprowadź imię użytkownika: ");
                scanf("%s", &u->user);
                u->type = tImie;
                break;
            }
            case KONIEC: {
                free(u);
                return NULL;
            }
        }
        printf("Wprowadź adres email użytkownika: ");
        scanf("%s", &u->mail);
        return u;
    }
}

int main( )
{
    struct stUser* uzytkownik = (struct stUser*)calloc(1, sizeof(sfUser));

    if (readUser(uzytkownik)) {
        printUser(uzytkownik);
        free(uzytkownik);
    }
}