# mkdir, rmdir function
## NAME
`mkdir` - make directories
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys/stat.h>
int mkdir(const char* pathname, mode_t mode);
int rmdir(const char* pathname);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* mkdir
  * 새로운 디렉토리 생성
  * `.`와 `..`은 자동으로 생성됨
* rmdir
  * 비어있는 디렉토리를 삭제
  * 해당 디렉토리를 참조하는 프로세스가 있는 가운데 연결 계쑤가 0이 된 경우 프로세스가 디렉토리를 close한 후에 디렉토리는 제거됨
