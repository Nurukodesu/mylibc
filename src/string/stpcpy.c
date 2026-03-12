#include "string.h"

char *stpcpy(char *restrict dst, const char *restrict src){
    while ((*dst=*src)) {
        dst++;
        src++;
    }
    return dst;
}