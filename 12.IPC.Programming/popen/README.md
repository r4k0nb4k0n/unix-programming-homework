# popen function
## NAME
`popen`, `pclose` - process I/O
## SYNOPSIS
```c
#include <stdio.h>
FILE *popen(const char *cmdstring, const char *mode);
int pclose(FILE *fd);
```
## RETURN VALUE
Return:
- `popen` : file pointer if OK, `NULL` on error
- `pclose` : termination status of cmdstring
