# 프로세스 식별자 (Process ID)
## NAME
getpid - return process ID of calling process
## SYNOPSIS
```
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
```
## RETURN VALUE
Return : Process ID

