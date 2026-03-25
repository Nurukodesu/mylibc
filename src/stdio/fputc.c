#include "internal.h"
#include <unistd.h>

int putc(int c, FILE *f) {

	if (f->wpos < f->wend && !((f->flags & _IO_LINE_BUF) && (c == '\n'))) {
		return *f->wpos++ = (unsigned char)c;
	}
	return __overflow(f, c);
}