#include "stddef.h"
#include <stdlib.h>

void *bsearch(const void *target, const void *base, size_t n, size_t size, int (*cmp)(const void *, const void *)){
	size_t l = 0;
	size_t r = n;
	while (l<r){
		size_t mid = l + (r-l)/2;
		void *ptr = (char*)base + mid*size;
		int res = cmp(target, ptr);
		if (res == 0){
			return ptr;
		} else if (res > 0){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return NULL;
}