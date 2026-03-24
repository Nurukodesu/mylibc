#include <stddef.h>

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long quot;
  long rem;
} ldiv_t;

typedef struct {
  long long quot;
  long long rem;
} lldiv_t;

int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);

int abs(int n);
long labs(long n);
long long llabs(long long n);

div_t div(int num, int den);
ldiv_t ldiv(long num, long den);
lldiv_t lldiv(long long num, long long den);

void *bsearch(const void *target, const void *base, size_t n, size_t size, int (const void * key, const void* ele));

extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *calloc(size_t n, size_t size);
extern void *realloc(void *ptr, size_t size);
extern void *reallocarray(void *ptr, size_t n, size_t size);