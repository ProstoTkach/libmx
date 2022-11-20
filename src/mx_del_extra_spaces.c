#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *mem = NULL;
    char *temp = NULL;
    int i = 0;
    int j = 0;

    if (!str)
        return NULL;
    else {
        mem = mx_strnew(mx_strlen(str));
        while (str[i]) {
            if (!(mx_is_space(str[i]))) {
                mem[j] = str[i];
                j++;
            }
            if (!(mx_is_space(str[i])) && mx_is_space(str[i + 1])) {
                mem[j] = ' ';
                j++;
            }
            i++;
        }
        temp = mx_strtrim(mem);
        mx_strdel(&mem);
        
        return temp;
    }
}


