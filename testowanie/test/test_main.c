#include <stdio.h>
#include "test_framework.h"

// deklaracje funkcji testów (z plików test_*.c)
void test_str_reverse(void);
void test_str_len_safe(void);
void test_add_sub(void);
void test_div_int(void);
void test_sum_array(void);

int main(void) {
    printf("== C mini test runner ==\n\n");

    test_str_reverse();
    test_str_len_safe();
    test_add_sub();
    test_div_int();
    test_sum_array();

    return tests_summary();
}
