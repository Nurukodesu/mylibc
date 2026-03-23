#include <ctype.h>

int iscntrl(int c) { return ((unsigned)c < 32) || (c == 127); }