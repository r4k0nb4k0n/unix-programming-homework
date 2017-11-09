# File Status
## NAME
stat, fstat, lstat - get file status
## SYNOPSIS
```
#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *pathname, struct stat *buf);
int fstat(int filedes, struct stat *buf);
int lstat(const char *pathname, struct stat *buf);
```
## RETURN VALUE
Return : 0 if OK, -1 on error

