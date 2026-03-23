#include <ctype.h>
#include <stdio.h>

int main(){
	char buf[12];
    print_string(itoa(-1234, buf+12));
	print_string("\n");
	return 0;
}