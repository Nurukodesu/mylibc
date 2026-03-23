#include <ctype.h>

int isxdigit(int c) {
    if ((unsigned)c - '0' < 10) return 1;
	return ((unsigned)(c - 1) & ~0x60) < 6;
}