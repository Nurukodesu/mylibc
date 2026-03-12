#include "unistd.h"
#include "errno.h"

extern ssize_t __sys_read(int fd, void *buf, size_t count);

ssize_t read(int fd, void *buf, size_t count){
    ssize_t ret = __sys_read(fd, buf, count);
    if (ret < 0){
        errno = (int) -ret;
        ret = -1;
    }
    return ret;
}