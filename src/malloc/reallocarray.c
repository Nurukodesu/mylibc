#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

void *reallocarray(void *ptr, size_t n, size_t size){
	size_t total_size;
	if (__builtin_mul_overflow(n, size, &total_size)){
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr, total_size);
}