# ftruncate, truncate
## NAME
ftruncate, truncate
## SYNOPSIS
```
#include <unistd.h>
#include <sys/types.h?

int ftruncate(int fd, off_t len);
int truncate(const char *path, off_t len);
```
## RETURN VALUE
Return: 0 if OK, -1 if error
