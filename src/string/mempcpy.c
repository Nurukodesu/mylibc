#include "string.h"

void *mempcpy(void *dst, const void *src, size_t n){
    unsigned char *d = dst;
    const unsigned char *s = src;
    while (n--) *d++ = *s++;
    return d;
}