#include "string.h"

// I felt like being really evil while writing this
// You have every right to hate me, future me
// ps: writing normally has better performance because of compiler optimization
int strncmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) n--, s1++, s2++;
    return n ? *(unsigned char *)s1 - *(unsigned char *)s2 : 0;
}