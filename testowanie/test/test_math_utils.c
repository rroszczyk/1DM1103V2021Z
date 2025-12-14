#include <limits.h>
#include "test_framework.h"
#include "math_utils.h"

void test_add_sub(void) {
    TEST_ASSERT_EQ_INT("add 2+2=4", 4, add_int(2, 2));
    TEST_ASSERT_EQ_INT("add -1+1=0", 0, add_int(-1, 1));
    TEST_ASSERT_EQ_INT("sub 5-8=-3", -3, sub_int(5, 8));
}

void test_div_int(void) {
    int out = 0;

    TEST_ASSERT_EQ_INT("div out==NULL -> -1", -1, div_int(10, 2, NULL));
    TEST_ASSERT_EQ_INT("div by zero -> -2", -2, div_int(10, 0, &out));

    out = 0;
    TEST_ASSERT_EQ_INT("div 10/2 returns 0", 0, div_int(10, 2, &out));
    TEST_ASSERT_EQ_INT("div 10/2 out==5", 5, out);

    out = 0;
    TEST_ASSERT_EQ_INT("div -9/2 returns 0", 0, div_int(-9, 2, &out));
    TEST_ASSERT_EQ_INT("div -9/2 out==-4 (trunc toward zero)", -4, out);
}

void test_sum_array(void) {
    long out = 0;

    TEST_ASSERT_EQ_INT("sum arr==NULL -> -1", -1, sum_array(NULL, 3, &out));
    TEST_ASSERT_EQ_INT("sum out==NULL -> -1", -1, sum_array((int[]){1,2,3}, 3, NULL));
    TEST_ASSERT_EQ_INT("sum n==0 -> -2", -2, sum_array((int[]){1,2,3}, 0, &out));

    int a[] = {1, 2, 3, 4};
    TEST_ASSERT_EQ_INT("sum returns 0", 0, sum_array(a, 4, &out));
    TEST_ASSERT("sum {1,2,3,4} == 10", out == 10);

    int b[] = {INT_MAX, 0, -1};
    TEST_ASSERT_EQ_INT("sum returns 0 (long accumulator)", 0, sum_array(b, 3, &out));
    TEST_ASSERT("sum {INT_MAX,0,-1} == INT_MAX-1", out == (long)INT_MAX - 1L);
}
