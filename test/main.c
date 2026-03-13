#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *s = calloc(1, 7);
    strcpy(s, "hello\n");
    print_string(s);
    free(s);
    return 0;
}