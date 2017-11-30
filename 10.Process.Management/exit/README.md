# 프로세스의 종료(exit)
## NAME
`exit` - terminate the current process
## SYNOPSIS
```c
#include <stdlib.h>
void exit(int status);

#include <unistd.h>
void _exit(int status);
```
## RETURN VALUE
Return : 
## Description
* exit
* _exit
* `int atexit(void (*function)(void));`

