# Symbolic link
## NAME
`readlink` - read value of a symbolic link
## SYNOPSIS
```c
#include <unistd.h>
int readlink(const char* pathname, char *buf, int bufsize);
```
## RETURN VALUE
Return: number of bytes read if OK, -1 on error
## Description
* pathname - 심볼릭 링크 파일경로
* buf - 심볼릭 링크 파일의 데이터를 읽어올 버퍼
* bufsize - 읽을 버퍼의 크기
* 심볼릭 링크 파일을 읽는다.
* buf는 null로 끝나지 않음
* open, read, close의 기능을 합함

