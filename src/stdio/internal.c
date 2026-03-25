#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "internal.h"
#include "unistd.h"

size_t __file_write(FILE *f, const unsigned char *s, size_t l) {
    int r = write(f->fd, s, l);
	return (r<0)? 0:r;
}

size_t __string_write(FILE *f, const unsigned char *src, size_t len) {
    size_t available = (f->wend > f->wpos) ? (f->wend - f->wpos) : 0;
    size_t to_copy = (len < available) ? len : available;

    if (to_copy > 0) {
        memcpy(f->wpos, src, to_copy);
        f->wpos += to_copy;
    }

    return len; 
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
    unsigned char uc = (unsigned char)c;

	if (f->buf == NULL) {
        if (f->write(f, &uc, 1) != 1) return EOF;
        return uc;
    }

    size_t pending = f->wpos - f->buf;

    if (pending > 0) {
        if ((size_t)f->write(f, f->buf, pending) != pending) {
            f->flags |= _IO_ERR;
            return EOF;
        }
    }

    if (f->fd != -1) f->wpos = f->buf;

    if (c != EOF) {
        *f->wpos++ = uc;
    }

    return uc;
}