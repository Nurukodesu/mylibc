#include "stdio.h"
#include <string.h>

int main(){
    char s[]="hello world!\n";
    print_string(memrchr(s, 'o', 12));
    return 0;
}