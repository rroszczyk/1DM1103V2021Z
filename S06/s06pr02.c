//
// Created by Radosław Roszczyk on 03.11.2021.
//
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Value;
    struct Node *Next;
};

void insertFirst(struct Node** ptrHead, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->Value = val;
    newNode->Next = (*ptrHead);         // wskaźnik aktualnej struktury zaczyna wskazywać poprzedni
    (*ptrHead) = newNode;
}

void insertAfter(struct Node* prevNode, int val)
{
    if (prevNode == NULL)
    {
        printf("nie istnieje wskazany element");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Value = val;
    newNode->Next = prevNode->Next;     // wskaźnij aktualnej struktury zaczyna wskazywać następny
    prevNode->Next = newNode;
}

void append(struct Node** ptrHead, int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *ptrHead;

    newNode->Value = val;
    newNode->Next = NULL;               // wskaźnij aktualnej struktury zaczyna wskazywać pusty

    if (*ptrHead == NULL)
    {
        *ptrHead = newNode;
        return;
    }
    while (last->Next != NULL)
        last = last->Next;

    last->Next = newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d \t", node->Value);
        node = node->Next;
    }
}

int main()
{
    struct Node *lista1 = NULL;
    struct Node *lista2 = NULL;

    int arr[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        insertFirst(&lista1, arr[i]);
        append(&lista2, arr[i]);
    }
    printf("Lista elementów typu int - elementy wstawiane od początku listy:\n");
    printList(lista1);
    printf("\n\n");

    printf("Lista elementów typu int - elementy wstawiane na końcu listy:\n");
    printList(lista2);
    printf("\n\n");

    return 0;
}