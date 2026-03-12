#include "unistd.h"
#include "string.h"
#include "stdio.h"

int print_string(const char *buf){
    if (!buf) return -1;
    return write(STDOUT, buf, strlen(buf));
}