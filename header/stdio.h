#pragma once

#include <stddef.h>

#define EOF -1

typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v)      __builtin_va_end(v)
#define va_arg(v, t)   __builtin_va_arg(v, t)
#define va_copy(d, s)  __builtin_va_copy(d, s)

#define putc(c,f) fputc(c, f)
#define putchar(c) fputc (c, stdout)

struct _IO_FILE;
typedef struct _IO_FILE FILE;

struct _IO_FILE{
	int fd;
    int flags;
    unsigned char *buf;
    unsigned char *rend, *rpos;
    unsigned char *wend, *wpos;
    size_t buf_size;
	size_t (*write)(FILE*, const unsigned char*, size_t);
};

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

extern int fflush(FILE *f);

extern int fputc(int c, FILE *f);
extern size_t fwrite(const void *ptr, size_t size, size_t n, FILE *restrict f);

extern int printf(const char *fmt, ...);
extern int vfprintf(FILE *f, const char *restrict fmt, va_list ap);

extern int print_string(const char *buf);