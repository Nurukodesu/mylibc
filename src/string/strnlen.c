#include "string.h"

size_t strnlen(const char *s, const size_t max){
    if (s==NULL) return 0;
    const char *p = s;
    while ((size_t) (p-s) != max && *p) p++;
    return p-s;
}
