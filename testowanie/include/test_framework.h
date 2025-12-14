#pragma once
#include <stdio.h>

typedef void (*test_fn_t)(void);

static int tests_run = 0;
static int tests_failed = 0;

#define TEST_ASSERT(MSG, EXPR) do {                           \
    tests_run++;                                              \
    if (!(EXPR)) {                                            \
        tests_failed++;                                       \
        printf("FAIL: %s  (line %d)\n", (MSG), __LINE__);      \
    } else {                                                  \
        printf("PASS: %s\n", (MSG));                          \
    }                                                         \
} while (0)

#define TEST_ASSERT_EQ_INT(MSG, EXP, ACT) do {                \
    int _exp = (EXP);                                         \
    int _act = (ACT);                                         \
    tests_run++;                                              \
    if (_exp != _act) {                                       \
        tests_failed++;                                       \
        printf("FAIL: %s  expected=%d actual=%d (line %d)\n",  \
               (MSG), _exp, _act, __LINE__);                  \
    } else {                                                  \
        printf("PASS: %s\n", (MSG));                          \
    }                                                         \
} while (0)

static inline int tests_summary(void) {
    printf("\n== Summary: %d/%d passed ==\n",
           tests_run - tests_failed, tests_run);
    return (tests_failed != 0) ? 1 : 0;
}
