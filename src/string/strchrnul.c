#include "string.h"

char *strchrnul(const char *s, int c) {
    for (; *s && *s != (char)c; s++);
    return (char *)s;
}