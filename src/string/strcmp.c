#include "string.h"

int strcmp(const char *l, const char *r){
    while (*l && *l == *r) l++, r++;
	return *(unsigned char *)l - *(unsigned char *)r;
}
