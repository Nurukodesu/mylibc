#include "string.h"

char *strncat(char *restrict dst, const char *restrict src, size_t n){
    char *end = dst + strlen(dst);
    size_t n_limit = strnlen(src, n); 
    mempcpy(end, src, n_limit);
    end[n_limit] = '\0';
    return dst;
}