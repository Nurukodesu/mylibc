#include <stdio.h>

#define _IO_READ    0x0001  // Stream is open for reading
#define _IO_WRITE   0x0002  // Stream is open for writing
#define _IO_UNBUF   0x0004  // Unbuffered
#define _IO_LINE_BUF 0x0008 // Flush on '\n'
#define _IO_EOF     0x0010  // EOF reached
#define _IO_ERR     0x0020  // Error occurred

#define BUFSIZE 4096

extern int __overflow (FILE *f, int c);