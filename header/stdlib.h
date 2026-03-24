#include <stddef.h>
#include <stdint.h>

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

typedef struct {
	intmax_t quot;
	intmax_t rem;
} imaxdiv_t;

extern int atoi(const char *nptr);
extern long atol(const char *nptr);
extern long long atoll(const char *nptr);

extern int abs(int n);
extern long labs(long n);
extern long long llabs(long long n);
extern intmax_t imaxabs(intmax_t n);

extern div_t div(int num, int den);
extern ldiv_t ldiv(long num, long den);
extern lldiv_t lldiv(long long num, long long den);
extern imaxdiv_t imaxdiv(intmax_t num, intmax_t den);

void *bsearch(const void *target, const void *base, size_t n, size_t size, int (const void * key, const void* ele));

extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *calloc(size_t n, size_t size);
extern void *realloc(void *ptr, size_t size);
extern void *reallocarray(void *ptr, size_t n, size_t size);