#include <ctype.h>

int islower(int c){
	return (unsigned) c-0x60 < 26;
}