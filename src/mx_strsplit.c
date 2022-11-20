#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int wordLen = 0;
    int i = 0;
    char **arr = NULL;

    if (!s)
        return NULL;
    arr = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            wordLen = mx_count_letters(s, c);
            arr[i] = mx_strndup(s, wordLen);
            s += wordLen;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}


