#include <ctype.h>
#include <stdlib.h>

// pass the end of the buffer for buf_end
// example:
// char s[12];
// itoa(1234, s+12);
// return value is pointer that points to beginning of the number
// space between buf_start and returned pointer will be unused
char *itoa(int n, char *buf_end) {
	char *p = buf_end;
	*--p = '\0';
	int v = (n < 0) ? n : -n; // for asymmetry
	do { 
		*--p = '0' - (v%10);
		v /= 10;
	} while (v);
	if (n < 0) *--p='-';
	return p;
}