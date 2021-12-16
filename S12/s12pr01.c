//
// Created by Radosław Roszczyk on 16.12.2021.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *last;
} *ptrNode, *ptrStos;

ptrNode delLast(ptrNode node)
{
    if (node != NULL)
    {
        if (node->last == NULL)
        {
            free( node );
            return NULL;
        } else {
            node->last = delLast(node->last);
            return node;
        }
    } else {
        return NULL;
    }
}

ptrNode add(ptrNode node, int x)
{
    if (node == NULL)
    {
        ptrNode n = malloc(sizeof *n);
        n->value = x;
        n->last = NULL;
        return n;
    } else {
        node->last = add(node->last, x);
        return node;
    }
}

void print(ptrNode l)
{
    while (l != NULL)
    {
        printf("%d -> ", l->value);
        l = l->last;
    }
    printf("NULL\n");
}

int main()
{
    ptrStos l = NULL;

    for (int i = 0; i <= 15; i += 3)
    {
        print(l);
        l = add(l, i);
    }
    while (l != NULL)
    {
        print(l);
        l = delLast(l);
    }
    print(l);
    return 0;
}