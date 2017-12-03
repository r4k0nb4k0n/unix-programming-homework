# getcwd function
## NAME
`getcwd` - Get current working directory
## SYNOPSIS
```c
#include <unistd.h>
char* getcwd(char* buf, size_t size);
```
## RETURN VALUE
Return: buf if OK, `NULL` on error
## Description
* buf: buffer
* size: 버퍼 크기
* 현재의 작업 디렉토리를 얻는다.
