#include <stddef.h>
#include <stdio.h>
#include "internal.h"
#include "unistd.h"

size_t __file_write(FILE *f, const unsigned char *s, size_t l) {
    int r = write(f->fd, s, l);
	return (r<0)? 0:r;
}

static unsigned char stdout_buf[BUFSIZE];

static FILE __stdout = {
	.fd = 1,
    .flags = _IO_LINE_BUF | _IO_WRITE,
    .buf = stdout_buf,
    .buf_size = BUFSIZE,
	.rpos = stdout_buf,
	.rend = stdout_buf,
    .wpos = stdout_buf,
    .wend = stdout_buf+BUFSIZE,
	.write = __file_write,
};

FILE* const stdout = &__stdout;

int __overflow(FILE *f, int c){
    size_t pending = f->wpos - f->buf;

    if (pending > 0) {
        if ((size_t)f->write(f, f->buf, pending) != pending) {
            f->flags |= _IO_ERR;
            return EOF;
        }
    }

    f->wpos = f->buf;

    if (c != EOF) {
        *f->wpos++ = (unsigned char)c;
    }

    return (unsigned char)c;
}