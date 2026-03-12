#pragma once

#include "stddef.h"

extern size_t strlen(const char *s);
extern size_t strnlen(const char *string, size_t maxlen);

extern int strcmp(const char *l, const char *r);
extern int strncmp(const char *l, const char *r, size_t n);
extern int memcmp(const void *l, const void  *r, size_t n);

extern void *mempcpy(void *dest, const void *src, size_t n);
extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memmove(void *dest, const void *src, size_t n);
extern void *memset(void *s, int c, size_t n);

extern char *stpcpy(char *restrict dst, const char *restrict src);
extern char *strcpy(char *restrict dst, const char *restrict src);
extern char *strcat(char *restrict dst, const char *restrict src);
extern char *strncat(char *restrict dst, const char *restrict src, size_t n);

extern char *strchr(const char *s, int c);
extern char *strrchr(const char *s, int c);
extern char *strchrnul(const char *s, int c);
extern void *memchr(const void *s, int c, size_t n);
extern void *memrchr(const void *s, int c, size_t n);