#include "internal.h"
#include <stdio.h>

int vsnprintf(char *s, size_t n, const char *fmt, va_list ap) {
    FILE f = {
		.buf = (unsigned char *) s,
        .wpos = (unsigned char *)s,
        .wend = (unsigned char *)s + (n > 0 ? n - 1 : 0),
        .write = __string_write,
        .fd = -1
    };
    
    int result = vfprintf(&f, fmt, ap);

    if (n > 0) {
        putc('\0', &f);
    }
	fflush(&f);
    return result;
}