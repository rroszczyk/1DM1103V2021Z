//
// Created by roszczyr on 16.12.2021.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char Znak;
    struct Node* Nodes[27];     // litery od A do Z + $
} *ptrTrie, tNode;

ptrTrie insert(ptrTrie t, char* napis)
{
    int idx = napis[0] - 'A';
}

// 0 - brak
// 1 - znaleziony
int find(ptrTrie t, char* napis)
{
}

int main(int argc, char **argv)
{
    char* napis = "Basia Ma Kota";

    int idx = napis[0] - 'A';

    printf("%d", idx);
    return 0;
}