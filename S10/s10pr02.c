//
// Created by Radosław Roszczyk on 01.12.2021.
// Selection Sort
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

void selectionSort(int arr[], int n, bool direction)
{
    int min_idx;

    for (int i = 0; i < n - 1; i++) {
        min_idx = i;

        for (int j = i + 1; j < n; j++)  {
            if (direction && (arr[j] < arr[min_idx])) {
                min_idx = j;
            } else if (!direction && (arr[j] > arr[min_idx])) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
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

    selectionSort(arr, n, ASC);
    printf("\nTablica posortowana w kolejności rosnącej: \n");
    printArray(arr, n);

    return 0;
}
