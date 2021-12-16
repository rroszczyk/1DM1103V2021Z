//
// Created by roszczyr on 16.12.2021.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int d;
    struct Node *left, *right;
} *ptrTree, tNode, *ptrNode;

//ptrTree insert(struct Node* t, int x)
ptrTree insert(ptrTree t, int x)
{
    if (t == NULL)
    {
        ptrNode n = malloc(sizeof *n);
        //tNode *n = malloc(sizeof *n);
        n->d = x;
        n->left = n-> right = NULL;
        return n;
    } else if (t->d > x) {
        t->left = insert(t->left, x);
        return t;
    } else if (t->d < x) {
        t->right = insert(t->right, x);
        return t;
    } else {
        return t;
    }
}

void print_tree(ptrTree t, int d)
{
    if (t != NULL)
    {
        if (t->right != NULL) {
            print_tree(t->right, d + 1);
        }
        for (int i = 0; i < d; i++) {
            printf("   ");
        }
        printf("%2d\n", t->d);
        if (t->left != NULL) {
            print_tree(t->left, d + 1);
        }
    }
}

int main(int argc, char **argv)
{
    ptrTree t = NULL;
    int num;

    for (int i = 0; i < 20; i++)
    {
        num = rand() % 100;
        t = insert(t, num);
        printf("%2d ", num);
    }
    printf("\n");

    print_tree(t, 0);

    return 0;
}