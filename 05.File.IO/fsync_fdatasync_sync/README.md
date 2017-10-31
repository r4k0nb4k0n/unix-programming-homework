# fsync, fdatasync, sync
## NAME
fsync, fdatasync
## SYNOPSIS
```
#include <unistd.h>

int fsync (int fd);
int fdatasync (int fd);
void sync (void);
```
## RETURN VALUE
Return: 0 if OK, -1 if error
