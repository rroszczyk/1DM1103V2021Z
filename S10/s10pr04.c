//
// Created by Radosław Roszczyk on 01.12.2021.
// Quick Sort
//
#include <stdio.h>
#include <stdbool.h>

#define ASC true
#define DSC false

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortIterative(int array[], int low, int high)
{
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int p = partition(array, low, high);

        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void quickSort(int array[], int n, bool direction)
{
    quickSortIterative(array, 0, n-1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = { 81, 76, 92, 66, 51, 22, 70, 86, 45, 68, 26, 95, 92, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Oryginalna tablica: \n");
    printArray(arr, n);

    quickSort(arr, n, ASC);
    printf("\nTablica posortowana w kolejności rosnącej: \n");
    printArray(arr, n);

    return 0;
}
