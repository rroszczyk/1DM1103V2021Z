//
// Created by Radosław Roszczyk on 03.11.2021.
//
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Value;
    struct Node *Next;
    struct Node *Prev;
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

//    printElement(getElement(&lista1, 2));
//    printElement(getElement(&lista1, 20));
struct Node* getElement(struct Node** ptrHead, int idx) {
    struct Node *node = *ptrHead;

    int i = 0;
    while (node != NULL) {
        if (i == idx) {
            return node;
        }
        node = node->Next;
        i++;
    }
    return NULL;
}

int getIndexOfElement(struct Node* node, int Value) {
    int i = 0;
    while (node != NULL) {
        if (node->Value == Value) {
            return i;
        }
        node = node->Next;
        i++;
    }
    return -1;
}

void printElement(struct Node* node) {
    if (node) {
        printf("Element: %d \n", node->Value);
    } else {
        printf("Element nie istnieje \n");
    }
}

int main()
{
    struct Node *lista1 = NULL;
    struct Node *lista2 = NULL;
    struct Node *lista3 = NULL;

    int arr[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        insertFirst(&lista1, arr[i]);
        append(&lista2, arr[i]);
    }

    printElement(getElement(&lista1, 2));
    printElement(getElement(&lista1, 20));

    printf("Element 40 ma na liście1 indeks %i \n", getIndexOfElement(lista1, 40));
    printf("Element 40 ma na liście2 indeks %i \n", getIndexOfElement(lista2, 40));
    printf("Element 40 ma na liście3 indeks %i \n", getIndexOfElement(lista3, 40));

    printf("Lista elementów typu int - elementy wstawiane od początku listy:\n");
    printList(lista1);
    printf("\n\n");

    printf("Lista elementów typu int - elementy wstawiane na końcu listy:\n");
    printList(lista2);
    printf("\n\n");

    return 0;
}