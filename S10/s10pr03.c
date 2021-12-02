//
// Created by Radosław Roszczyk on 01.12.2021.
// Insertion Sort
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

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
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

    insertionSort(arr, n);
    printf("\nTablica posortowana w kolejności rosnącej: \n");
    printArray(arr, n);

    return 0;
}
