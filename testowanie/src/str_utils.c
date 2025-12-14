#include "str_utils.h"
#include <string.h>

int str_reverse_inplace(char *s) {
    if (!s) return -1;
    size_t n = strlen(s);
    for (size_t i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
    return 0;
}

size_t str_len_safe(const char *s) {
    if (!s) return 0u;
    return strlen(s);
}
