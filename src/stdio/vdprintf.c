#include "internal.h"

int vdprintf(int fd, const char *fmt, va_list ap) {
    FILE f = {
        .fd = fd,
        .write = __file_write,
        .flags = _IO_UNBUF,
        .buf = NULL,       
        .wpos = NULL,
        .wend = NULL
    };

    return vfprintf(&f, fmt, ap);
}