#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    char *tmp = mx_strnew(mx_strlen(s1));
    
    mx_strcpy(tmp, s1);
    return tmp;
}


