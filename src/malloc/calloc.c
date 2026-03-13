#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void *calloc(size_t n, size_t size){
	size_t total_size;
	if (__builtin_mul_overflow(n, size, &total_size)) {
        errno = ENOMEM;
        return NULL;
    }
	void *ptr = malloc(size);
	if (ptr) memset(ptr, 0, total_size);
	return ptr;
}