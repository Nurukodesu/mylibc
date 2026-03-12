#pragma once

#include "stddef.h"
#include "sys/types.h"

#define STDIN       0
#define STDOUT      1
#define STDERR      2

#define O_RDONLY 0x00
#define O_WRONLY 0x01
#define O_RDWR 0x02
#define O_CREAT 0x40
#define O_EXCL 0x80
#define O_TRUNC 0x200
#define O_APPEND 0x400
#define O_NONBLOCK 0x800
#define O_DSYNC 0x1000
#define O_SYNC 0x2000
#define O_CLOEXEC 0x4000

extern ssize_t read(int fd, void *buf , size_t count);
extern ssize_t write(int fd, const void *buf, size_t count);
extern ssize_t open(const char *path, int flags, mode_t mode);
extern void _exit(int status);