#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    const char *str;
    
    for (str = s; *str; ++str) {
    }
    return (str - s);
}


