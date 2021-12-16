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
    if (t == NULL) {
        t = calloc(1, sizeof(tNode));
        if (napis[0] == '\0')
        {
            t->Znak = '$';
            return t;
        }
        t->Znak = napis[0];
    }

    int idx = napis[0] - 'A';
    t->Nodes[idx] = insert(t->Nodes[idx], &napis[1]);
    return t;
}

// 0 - brak
// 1 - znaleziony
int find(ptrTrie t, char* napis)
{
    if (t == NULL) {
        return 0;
    }
    if (t->Znak == '$') {
        return 1;
    }
    int idx = napis[0] - 'A';
    return find(t->Nodes[idx], &napis[1]);
}

int main(int argc, char **argv)
{
    ptrTrie Trie = NULL;

    Trie = insert(Trie, "ABAKUS");
    printf("%d", find(Trie, "ABAKUS"));
    return 0;
}