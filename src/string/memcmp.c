#include "string.h"

int memcmp(const void *l, const void *r, size_t n) {
    const unsigned char * lp = l;
    const unsigned char *rp = r;
    while (n && (*lp == *rp)) n--, lp++, rp++;
    return n ? *lp - *rp : 0;
}
