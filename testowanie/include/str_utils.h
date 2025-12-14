#pragma once
#include <stddef.h>

/**
 * Reverse string in place.
 * Returns 0 on success, -1 if s == NULL.
 */
int str_reverse_inplace(char *s);

/**
 * Safe length:
 * Returns length of string, or 0 if s == NULL.
 */
size_t str_len_safe(const char *s);
