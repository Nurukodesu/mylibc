#include "ctype.h"
#include "internal.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int vfprintf(FILE *f, const char *restrict fmt, va_list ap) {
	int count = 0;
	while (*fmt) {
		if (*fmt != '%') {
			if (putc(*fmt++, f) == EOF) return -1;
			count++;
			continue;
		}

		fmt++;
		switch (*fmt++) {
		case 's': {
			char *s = va_arg(ap, char *);
			size_t len = strlen(s);
			if (fwrite(s, 1, len, f) != len) return -1;
			count += len;
			continue;
		}
		case 'd': {
			int d = va_arg(ap, int);
			char buf[21];
			char *s = itoa(d, buf + 21);
			size_t len = (buf + 21) - s;
			if (fwrite(s, 1, len, f) != len) return -1;
			count += len;
			continue;
		}
		default:
			return -1;
		}
	}

	return count;
}