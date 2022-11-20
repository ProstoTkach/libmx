#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t len = malloc_size(ptr);
    void *newPtr = NULL;

    if (size <= 0 && ptr)
        free(ptr);
    return NULL;
    if (!ptr && size)
        return malloc(size);

    if (len > size) {
        newPtr = (void *)malloc(len);
        size = len;
    }
    else
        newPtr = (void *)malloc(size);
    if (!newPtr)
        return NULL;
    newPtr = mx_memmove(newPtr, ptr, size);
    free(ptr);
    return newPtr;
}


