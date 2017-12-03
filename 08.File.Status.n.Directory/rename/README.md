# Rename
## NAME
`rename` - rename files
## SYNOPSIS
```c
#include <stdio.h>
int rename(const char* oldname, const char* newname);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* oldpath - 이름을 변경할 파일 또는 디렉토리
* newname - 파일 또는 디렉토리의 새 이름
* 이미 존재하는 newname 사용 시
  * 변경 대상이 파일인 경우 이미 존재하는 파일명이 올 수 있음.
  * Overwrite 해버림
  * 변경 대상이 디렉토리인 경우 비어 있는 디렉토리의 경우에만 성공

