#include "unistd.h"
#include "errno.h"

extern ssize_t __sys_write(int fd, const void *buf, size_t count);

ssize_t write(int fd, const void *buf, size_t count){
    ssize_t ret = __sys_write(fd, buf, count);
    if (ret < 0){
        errno = (int) -ret;
        ret = -1;
    }
    return ret;
}