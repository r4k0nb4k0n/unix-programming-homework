# fopen function
## NAME
fopen - stream open functions
## SYNOPSIS
```
#include <stdio.h>
FILE *fopen(const char *pathname, const char *type);
```
## RETURN VALUE
Return : file pointer if OK, NULL on error
## Description
* pathname : 파일 경로
* type : 파일 접근 모드
	* "r" or "rb" : O_RDONLY
	* "w" or "wb" : O_WRONLY | O_CREAT | O_TRUNC
	* "a" or "ab" : O_WRONLY | O_APPEND | O_CREAT
	* "r+" or "r+b" or "rb+" : O_RDWR
	* "w+" or "w+b" or "wb+" : O_RDWR | O_CREAT | O_TRUNC
	* "a+" or "a+b" or "ab+" : O_RDWR | O_APPEND | O_CREAT
* File 구조체와 버퍼를 할당하며 FILE 구조체 내부의 각 필드들을 초기화한 후에 open을 호출하여 file descriptor를 얻음
* 파일이 새로 생성되는 경우 0666의 permission (umask로 조정)
