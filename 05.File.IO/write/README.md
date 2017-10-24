# write function
## NAME
write - write data from an open file
## SYNOPSIS
```
#include <unistd.h>
ssize_t write(int filedes, const void *buf, size_t nbytes);
```
## RETURN VALUE
Return : number of bytes written if OK, -1 on error
