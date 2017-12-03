# chdir, fchdir function
## NAME
`chdir`, `fchdir` - change working directory
## SYNOPSIS
```c
#include <unistd.h>
int chdir(const char* pathname);
int fchdir(int filedes);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* chdir
  * pathname : 변경할 디렉토리 경로
* fchdir
  * filedes : file descriptor
* 모든 프로세스는 현재의 작업 디렉토리(working directory)를 가짐.
