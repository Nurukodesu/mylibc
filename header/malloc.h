#include <stddef.h>

extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *calloc(size_t n, size_t size);
extern void *realloc(void *ptr, size_t size);
extern void *reallocarray(void *ptr, size_t n, size_t size);