//
// Created by Radosław Roszczyk on 01.12.2021.
// Bubble Sort
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

void bubbleSort(int array[], int size, bool direction)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (direction && array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
            } else if (!direction && array[i] < array[i + 1]) {
                swap(&array[i + 1], &array[i]);
            }
        }
    }
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

    bubbleSort(arr, n, ASC);
    printf("\nTablica posortowana w kolejności rosnącej: \n");
    printArray(arr, n);

    return 0;
}
