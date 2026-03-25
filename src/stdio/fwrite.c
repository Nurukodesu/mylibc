#include "internal.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t fwrite(const void *ptr, size_t size, size_t n, FILE *restrict f){
	size_t pending = size * n;
	size_t available = f->wend - f->wpos;
	const unsigned char *src = ptr;
	if (available >= pending) {
		memcpy(f->wpos, src, pending);
		f->wpos += pending;
		return n;
	}

	if (fflush(f)==EOF) return 0;

	return f->write(f, src, pending)/size;
}