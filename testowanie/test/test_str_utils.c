#include <string.h>
#include "test_framework.h"
#include "str_utils.h"

void test_str_reverse(void) {
    char a[] = "";
    TEST_ASSERT_EQ_INT("reverse('') returns 0", 0, str_reverse_inplace(a));
    TEST_ASSERT("reverse('') stays ''", strcmp(a, "") == 0);

    char b[] = "x";
    TEST_ASSERT_EQ_INT("reverse('x') returns 0", 0, str_reverse_inplace(b));
    TEST_ASSERT("reverse('x') stays 'x'", strcmp(b, "x") == 0);

    char c[] = "abcd";
    TEST_ASSERT_EQ_INT("reverse('abcd') returns 0", 0, str_reverse_inplace(c));
    TEST_ASSERT("reverse('abcd') => 'dcba'", strcmp(c, "dcba") == 0);

    char d[] = "abcde";
    TEST_ASSERT_EQ_INT("reverse('abcde') returns 0", 0, str_reverse_inplace(d));
    TEST_ASSERT("reverse('abcde') => 'edcba'", strcmp(d, "edcba") == 0);

    TEST_ASSERT_EQ_INT("reverse(NULL) returns -1", -1, str_reverse_inplace(NULL));
}

void test_str_len_safe(void) {
    TEST_ASSERT("len(NULL)==0", str_len_safe(NULL) == 0u);
    TEST_ASSERT("len('')==0", str_len_safe("") == 0u);
    TEST_ASSERT("len('abc')==3", str_len_safe("abc") == 3u);
}
