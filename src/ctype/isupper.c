#include <ctype.h>

int isupper(int c){
	return (unsigned) c-0x40 < 26;
}