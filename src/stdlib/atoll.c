#include <ctype.h>
#include <stdlib.h>

long long atoll(const char *nptr) {
	while (isspace(*nptr)) nptr++;
	long long neg = 0;
	switch (*nptr){
		case '-': neg = 1;
		case '+': nptr++;
	}
	long long ret = 0;
	while (isdigit(*nptr)) {
		ret = ret * 10 - (*nptr - '0');
		nptr++;
	}
	return neg ? ret : -ret;
}