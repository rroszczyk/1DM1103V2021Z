//
// Created by Radosław Roszczyk on 10.11.2021.
//

#ifndef S_SB_H
#define S_SB_H

#define SB_FAILURE				-1
#define SB_MAX_FRAG_LENGTH		4096

typedef struct _StringFragment {
    struct _StringFragment	*next;
    int						length;
    char					*str;
} StringFragment;

typedef struct _StringBuilder {
    struct _StringFragment	*root;
    struct _StringFragment	*trunk;
    int						length;
} StringBuilder;

StringBuilder *sbCreate();
int sbEmpty(StringBuilder *sb);
int sbAppend(StringBuilder *sb, const char *str);
int sbAppendf(StringBuilder *sb, const char *format, ...);
char *sbConcat(StringBuilder *sb);
void sbReset(StringBuilder *sb);
void sbFree(StringBuilder *sb);

#endif //S_SB_H
