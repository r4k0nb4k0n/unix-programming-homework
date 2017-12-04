# File Truncation
## NAME
`truncate`, `ftruncate` - truncate a file to a specified length
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>
int truncate(const char *path, off_t length);
int ftruncate(int fd, off_t length);
```
## RETURN VALUE
Return : `0` if OK, `-1` on error
## Description
* `truncate`
* `ftruncate`
* 기존의 파일을 length 바이트로 잘라낸다.
* 만약 이전 파일의 크기가 length보다 작았으면?
	* Hole(윈도우 계열에서는 sparse) file 생성

