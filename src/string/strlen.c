#include "string.h"

size_t strlen(const char *s){
    if (s==NULL) return 0;
    const char *p = s;
    while (*p) p++;
    return p-s;
}