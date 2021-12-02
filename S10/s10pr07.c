//
// Created by Radosław Roszczyk on 01.12.2021.
// Hanoi
//
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <math.h>

struct Stack
{
    unsigned capacity;
    int top;
    int *array;
};

// tworzy stos
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(stack -> capacity * sizeof(int));
    return stack;
}

// sprawdza czy stos jest pełen
int isFull(struct Stack* stack)
{
    return (stack->top == stack->capacity - 1);
}

// sprawdza czy stos jest pusty
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}

// funkcja wkłada element na stos
void push(struct Stack *stack, int item)
{
    if (isFull(stack)) {
        return;
    }
    stack -> array[++stack -> top] = item;
}

// funkcja zdejmuje element ze stosu
int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack -> array[stack -> top--];
}

void moveDisk(char src, char dsc, int num)
{
    printf("\n Przenieś dysk %d z drążka %c na drążek %c", num, src, dsc);
}

void moveDisksBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    if (pole1TopDisk == INT_MIN)           // When pole 1 is empty
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    else if (pole2TopDisk == INT_MIN)      // When pole2 pole is empty
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
    else if (pole1TopDisk > pole2TopDisk)  // When top disk of pole1 > top disk of pole2
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
    else                                   // When top disk of pole1 < top disk of pole2
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

void towers(int num, struct Stack *src, struct Stack *aux, struct Stack *dest)
{
    int i, total_num_of_moves;
    char s = 'A', d = 'C', a = 'B';

    // If number of disks is even, then interchange
    // destination pole and auxiliary pole
    if (num % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num) - 1;

    // Larger disks will be pushed first
    for (i = num; i >= 1; i--)
        push(src, i);

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d);

        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a);

        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

int main()
{
    int n = 2;

    struct Stack *src, *dest, *aux;

    src = createStack(n);
    aux = createStack(n);
    dest = createStack(n);

    towers(n, src, aux, dest);
    return 0;
}
