//
// Created by Radosław Roszczyk on 03.11.2021.
//
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    void  *Data;
    struct Node *Next;
};

void insertFirst(struct Node** ptrHead, void *newData, size_t dataSize)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->Data  = malloc(dataSize);  // alokacja pamięci dla danych
    newNode->Next = (*ptrHead);         // wskaźnik aktualnej struktury zaczyna wskazywać poprzedni

    for (int i = 0; i < dataSize; i++) {    // kopiowanie danych
        *(char*)(newNode->Data + i) = *(char *)(newData + i);
    }
    (*ptrHead) = newNode;
}

void insertAfter(struct Node* prevNode, void *newData, size_t dataSize)
{
    if (prevNode == NULL)
    {
        printf("nie istnieje wskazany element");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data  = malloc(dataSize);  // alokacja pamięci dla danych
    newNode->Next = prevNode->Next;     // wskaźnij aktualnej struktury zaczyna wskazywać następny

    for (int i = 0; i < dataSize; i++) {    // kopiowanie danych
        *(char*)(newNode->Data + i) = *(char *)(newData + i);
    }
    prevNode->Next = newNode;
}

void append(struct Node** ptrHead, void *newData, size_t dataSize)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *ptrHead;

    newNode->Data  = malloc(dataSize);  // alokacja pamięci dla danych
    newNode->Next = NULL;               // wskaźnij aktualnej struktury zaczyna wskazywać pusty

    for (int i = 0; i < dataSize; i++) {    // kopiowanie danych
        *(char*)(newNode->Data + i) = *(char *)(newData + i);
    }

    if (*ptrHead == NULL)
    {
        *ptrHead = newNode;
        return;
    }
    while (last->Next != NULL)
        last = last->Next;

    last->Next = newNode;
}

void deleteList(struct Node** ptrHead)
{
    struct Node* current = *ptrHead;
    struct Node* next;

    while (current != NULL)
    {
        next = current->Next;
        free(current);
        current = next;
    }

    *ptrHead = NULL;
}

void printList(struct Node *node, void (*handle)(void *))
{
    while (node != NULL)
    {
        (*handle)(node->Data);
        node = node->Next;
    }
}

void printInt(void *n)
{
    printf(" %d", *(int*)n);
}

void printFloat(void *f)
{
    printf(" %g", *(float *)f);
}

int main()
{
    struct Node *lista1 = NULL;
    struct Node *lista2 = NULL;

    int arr[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        insertFirst(&lista1, &arr[i], sizeof(int));
        append(&lista2, &arr[i], sizeof(int));
    }
    printf("Lista elementów typu int - elementy wstawiane od początku listy:\n");
    printList(lista1, printInt);
    printf("\n\n");

    printf("Lista elementów typu int - elementy wstawiane na końcu listy:\n");
    printList(lista2, printInt);
    printf("\n\n");

    unsigned float_size = sizeof(float);
    struct Node *start = NULL;
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    for (int i=4; i>=0; i--) {
        insertFirst(&start, &arr2[i], float_size);
    }
    printf("Lista elementów typu float \n");
    printList(start, printFloat);

    return 0;
}