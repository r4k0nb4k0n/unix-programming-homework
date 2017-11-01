# Binary I/O function
## NAME
fread, fwrite - binary stream input/output
## SYNOPSIS
```
#include <stdio.h>
size_t fread(void *ptr, size_t size, size_t nobj, FILE *fp);
size_t fwrite(const void *ptr, size_t size, size_t nobj, FILE *fp);
```
## RETURN VALUE
Return : number of objects read or written
## Description
* ptr - 버퍼의 시작 주소
* size - 입력 단위의 크기
* nobj - 입출력을 수행할 객체 수
* fp - 파일 포인터
* 이진 배열에 대한 입출력
* 구조체에 대한 
