# read function
## NAME
read - read data from an open file
## SYNOPSIS
```
#include <unistd.h>
ssize_t read(int filedes, void *buf, size_t nbytes);
```
## RETURN VALUE
Return: number of bytes read. 0 if end of file, -1 on error.
## Description

