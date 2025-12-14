#include "math_utils.h"

int add_int(int a, int b) { return a + b; }
int sub_int(int a, int b) { return a - b; }

int div_int(int a, int b, int *out) {
    if (!out) return -1;
    if (b == 0) return -2;
    *out = a / b;
    return 0;
}

int sum_array(const int *arr, size_t n, long *out) {
    if (!arr || !out) return -1;
    if (n == 0) return -2;

    long s = 0;
    for (size_t i = 0; i < n; i++) {
        s += arr[i];
    }
    *out = s;
    return 0;
}
