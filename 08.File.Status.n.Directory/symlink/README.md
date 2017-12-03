# Symboloc Link
## NAME
`symlink` - make a new name for a file
## SYNOPSIS
```c
#include <unistd.h>
int symlink(const char* actualpath, const char* sympath);
```
## RETURN VALUE
Return: symlink - 0 if OK, -1 on error
## Description
* actualpath - 심볼릭 링크가 가리킬 대상 파일의 경로이름
* sympath - 생성될 심볼릭 링크의 경로이름
* 파일에 대한 간접 포인터 생성
* 실제 파일에 대한 경로 저장

