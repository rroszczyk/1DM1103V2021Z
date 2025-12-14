#pragma once
#include <stddef.h>

int add_int(int a, int b);
int sub_int(int a, int b);

/**
 * Safe division for ints:
 * - returns 0 on success and stores result in *out
 * - returns -1 if out == NULL
 * - returns -2 if b == 0
 */
int div_int(int a, int b, int *out);

/**
 * Sum of array elements:
 * - returns 0 on success and stores sum in *out
 * - returns -1 if arr == NULL or out == NULL
 * - returns -2 if n == 0
 */
int sum_array(const int *arr, size_t n, long *out);
