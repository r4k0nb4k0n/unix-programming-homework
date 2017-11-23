# 프로세스의 생성(fork)
## NAME
fork - create a child process
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork();
```
## RETURN VALUE
Return
* Parent - Process ID of Child
* Child - 0, -1 on error
## Description

