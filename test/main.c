#include <ctype.h>
#include <stdio.h>

int main(){
	char buf[] = {toupper('a'), tolower('+'), '\n', '\0'};
	print_string(buf);
	return 0;
}