#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0)
        return -2;

    (*lineptr) = (char *) mx_realloc(*lineptr, buf_size);
    mx_memset((*lineptr), '\0', malloc_size((*lineptr)));
    size_t bytes = 0;
    char temp;

    if (read(fd, &temp, 1)) {
        if (temp == delim)
            return bytes;

        (*lineptr) = (char *) mx_realloc(*lineptr, bytes + 1);
        (*lineptr)[bytes] = temp;
        bytes++;
    }
    else
        return -1;

    while (read(fd, &temp, 1)) {
        if (temp == delim)
            break;
        
        if (bytes >= buf_size)
            (*lineptr) = (char *) mx_realloc(*lineptr, bytes + 1);

        (*lineptr)[bytes] = temp;

        bytes++;
    }

    (*lineptr) = (char *) mx_realloc(*lineptr, bytes + 1);

    size_t freeData = malloc_size((*lineptr)) - bytes;
    mx_memset(&(*lineptr)[bytes], '\0', freeData);

    return bytes + 1;
}


