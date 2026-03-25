#include <unistd.h>
#include "internal.h"

int fflush(FILE *f) {
	size_t pending = f->wpos - f->buf;
	if (pending > 0) { 
		ssize_t written = f->write(f, f->buf, pending); 
		if (written< (ssize_t)pending){
			f->flags |= _IO_ERR;
			return EOF;
		}
	}
	f->rpos = f->wpos = f->buf;
	return 0;
}