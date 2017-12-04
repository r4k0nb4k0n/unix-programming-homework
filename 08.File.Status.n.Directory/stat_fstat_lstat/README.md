# File Status
## NAME
`stat`, `fstat`, `lstat` - get file status
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *pathname, struct stat *buf);
int fstat(int filedes, struct stat *buf);
int lstat(const char *pathname, struct stat *buf);
```
## RETURN VALUE
Return : `0` if OK, `-1` on error
## Description
* `stat`
* `fstat`
* `lstat`
	* pathname : 정보를 조회할 파일의 경로
	* filedes : 정보를 조회할 파일의 디스크립터
	* stat buf : 파일 정보를 저장할 `stat` 구조체
* lstat vs. stat?
## lstat function
[lstat.c](./lstat.c)
