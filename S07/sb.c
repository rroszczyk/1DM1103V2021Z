//
// Created by Radosław Roszczyk on 10.11.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "sb.h"

/*
 * sbCreate returns a pointer to a new StringBuilder or NULL if memory is not
 * available.
 */
StringBuilder *sbCreate()
{
    StringBuilder *sb = (StringBuilder *)calloc(sizeof(StringBuilder), 1);
    return sb;
}

/*
 * sbEmpty returns non-zero if the given StringBuilder is empty.
 */
int sbEmpty(StringBuilder *sb)
{
    return (sb->root == NULL);
}

/*
 * sbAppend adds a copy of the given string to a StringBuilder.
 */
int sbAppend(StringBuilder *sb, const char *str)
{
    int length = 0;
    StringFragment *frag = NULL;

    if (NULL == str || '\0' == *str) {
        return sb->length;
    }

    length = strlen(str);
    frag = (StringFragment *)malloc(sizeof(StringFragment) + (sizeof(char) * length));
    if (NULL == frag) {
        return SB_FAILURE;
    }

    frag->next = NULL;
    frag->length = length;
    memcpy((void *)&frag->str, (const void *)str, sizeof(char) * (length + 1));

    sb->length += length;
    if (NULL == sb->root) {
        sb->root = frag;
    } else {
        sb->trunk->next = frag;
    }

    sb->trunk = frag;

    return sb->length;
}

/*
 * sbAppendf adds a copy of the given formatted string to a StringBuilder.
 */
int sbAppendf(StringBuilder *sb, const char *format, ...)
{
    int rc = 0;
    char buf[SB_MAX_FRAG_LENGTH];
    va_list args;

    va_start (args, format);
    rc = vsnprintf(&buf[0], SB_MAX_FRAG_LENGTH, format, args);
    va_end(args);

    if (0 > rc)
        return SB_FAILURE;

    return sbAppend(sb, buf);
}

/*
 * sb_concat returns a concatenation of strings that have been appended to the
 * StringBuilder. It is the callers responsibility to free the returned
 * reference.
 *
 * The StringBuilder is not modified by this function and can therefore continue
 * to be used.
 */
char *sbConcat(StringBuilder *sb)
{
    char *buf = NULL;
    char *c = NULL;
    StringFragment *frag = NULL;

    buf = (char *) malloc((sb->length + 1) * sizeof(char));
    if (NULL == buf)
        return NULL;

    c = buf;
    for (frag = sb->root; frag; frag = frag->next) {
        memcpy(c, &frag->str, sizeof(char) * frag->length);
        c += frag->length;
    }

    *c = '\0';

    return buf;
}

/*
 * sb_reset resets the given StringBuilder, freeing all previously appended
 * strings.
 */
void sbReset(StringBuilder *sb)
{
    StringFragment *frag = NULL;
    StringFragment *next = NULL;

    frag = sb->root;
    while (frag) {
        next = frag->next;
        free(frag);
        frag = next;
    }

    sb->root = NULL;
    sb->trunk = NULL;
    sb->length = 0;
}

/*
 * sb_free frees the given StringBuilder and all of its appended strings.
 */
void sbFree(StringBuilder *sb)
{
    sbReset(sb);
    free(sb);
}