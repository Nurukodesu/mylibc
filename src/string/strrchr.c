#include "string.h"

// Note for future self: 
// The ternary operation is for patching the the case when c == NULL cuz the loop will end before setting r to s
char *strrchr(const char *s, int c) {
    char *r = 0;
    for (; *s; s++) if (*s == (char)c) r = (char *)s;
    return (char)c ? r : (char *)s;
}