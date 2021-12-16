//
// Created by Radosław Roszczyk on 08.12.2021.
//
#include <stdio.h>
#include <stdlib.h>

// XOR
//  p  q  p^q
//  0  0   0
//  0  1   1
//  1  0   1
//  1  1   0


// element listy
struct Node {
    int data;
    struct Node* xnode;
};

struct Node* Xor(struct Node* x, struct Node* y)
{
    return (struct Node*)((unsigned int)x ^ (unsigned int)y);
}

// dodaje element na początku listy
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->xnode = (*head_ref);

    if ((*head_ref) != NULL) {
        (*head_ref)->xnode = Xor(new_node, (*head_ref)->xnode);
    }

    (*head_ref) = new_node;
}

// dodaje element za wskazanym
void insertAfter(struct Node** head_ref, struct Node* prev, int new_data)
{
    if (*head_ref == NULL || prev == NULL) {
        return;
    }

    struct Node* curr = *head_ref;
    struct Node* last = NULL;
    struct Node* next;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    while (curr != NULL) {
        next = Xor(last, curr->xnode);

        last = curr;
        curr = next;
        if (last == prev) break;
    }

    new_node->xnode = Xor(prev, next);
    prev->xnode = Xor(Xor(prev->xnode, next), new_node);
    next->xnode = Xor(new_node, Xor(next->xnode, prev));
}

// dodaje element na końcu listy
void append(struct Node** head_ref, int new_data)
{
    struct Node* curr = *head_ref;
    struct Node* last = NULL;
    struct Node* next;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->xnode = *head_ref;
        *head_ref = new_node;
        return;
    }

    while (curr != NULL) {
        next = Xor(last, curr->xnode);

        last = curr;
        curr = next;
    }
    new_node->xnode = Xor(last, NULL);
    last->xnode = Xor(last->xnode, new_node);
}

// wypisuje wszystkie elementy listy od początku oraz od końca
void printList(struct Node* node)
{
    struct Node* curr = node;
    struct Node* prev = NULL;
    struct Node* next;

    printf("\nOd początku \n");
    while (curr != NULL) {
        printf(" %d ", curr->data);
        next = Xor(prev, curr->xnode);

        prev = curr;
        curr = next;
    }

    curr = prev;
    printf("\nOd końca \n");
    while (curr != NULL) {
        printf(" %d ", curr->data);
        prev = Xor(next, curr->xnode);

        next = curr;
        curr = prev;
    }
    printf("\n");
}

// usuwa wskazany element listy
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL) {
        return;
    }

    struct Node* curr = *head_ref;
    struct Node* prev = NULL;
    struct Node* next;

    while (curr != NULL) {
        next = Xor(prev, curr->xnode);

        if (curr == del) break;
        prev = curr;
        curr = next;
    }

    if (prev != NULL) {
        prev->xnode = Xor(Xor(prev->xnode, del), next);
    }
    if (next != NULL) {
        next->xnode = Xor(prev, Xor(next->xnode, del));
    }

    if (*head_ref == del) {
        *head_ref = next;
    }

    free(del);
}

// main
int main()
{
    struct Node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    append(&head, 9);
    insertAfter(&head, head->xnode, 8);

    printf("Utworzona lista: ");
    printList(head);

    printf("\nLista po usunięciu drugiego elementu: ");
    deleteNode(&head, head->xnode);
    printList(head);

    return 0;
}
