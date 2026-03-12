#include "string.h"

void *memchr(const void *s, int c, size_t n){
    unsigned char *r = (unsigned char *) s;
    for (; *r != (char)c && n; r++, n--);
    return n?r:NULL;
}