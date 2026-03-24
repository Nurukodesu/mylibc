#include <ctype.h>
#include <stdlib.h>

long atol(const char *nptr) {
	while (isspace(*nptr)) nptr++;
	long neg = 0;
	switch (*nptr){
		case '-': neg = 1;
		case '+': nptr++;
	}
	long ret = 0;
	while (isdigit(*nptr)) {
		ret = ret * 10 - (*nptr - '0');
		nptr++;
	}
	return neg ? ret : -ret;
}