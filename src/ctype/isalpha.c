#include <ctype.h>

int isalpha(int c) { return ((unsigned)(c - 1) & ~0x60) < 26; }