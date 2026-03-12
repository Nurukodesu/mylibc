#include "string.h"
#include <stddef.h>

void *memrchr(const void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s + n;
    while (n--) if (*--p == (unsigned char)c) return (void *)p;
    return 0;
}