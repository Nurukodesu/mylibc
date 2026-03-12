#include "string.h"
#include <stddef.h>

void *memset(void *s, int c, size_t n){
    while(n--) *(unsigned char*)s++ = (unsigned char) c; 
    return s;
}