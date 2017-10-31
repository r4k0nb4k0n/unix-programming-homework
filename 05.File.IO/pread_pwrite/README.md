# pread, pwrite
## NAME
pread, pwrite
## SYNOPSIS
```
#define _XOPEN_SOURCE 500
#include <unistd.h>

ssize_t pread (int fd, void *buf, size_t count, off_t pos);
ssize_t pwrite (int fd, void *buf, size_t count, off_t pos);
```
## RETURN VALUE
Return: number of bytes read or written, 0 if EOF in pread, 0 if nothing written in pwrite, -1 if error
