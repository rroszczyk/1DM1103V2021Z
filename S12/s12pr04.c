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
}

// 0 - brak
// 1 - znaleziony
int find(ptrTrie t, char* napis)
{
}

int main(int argc, char **argv)
{
    return 0;
}