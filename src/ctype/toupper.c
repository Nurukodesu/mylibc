#include <ctype.h>

int tolower(int c){
	return c^(((unsigned)(c - 'a') < 26)<<5);
}