#include <ctype.h>
#include <stdlib.h>

int atoi(const char *nptr) {
	while (isspace(*nptr)) nptr++;
	int neg = 0;
	switch (*nptr){
		case '-': neg = 1;
		case '+': nptr++;
	}
	int ret = 0;
	while (isdigit(*nptr)) {
		ret = ret * 10 - (*nptr - '0');
		nptr++;
	}
	return neg ? ret : -ret;
}