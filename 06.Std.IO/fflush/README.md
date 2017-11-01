# Buffer Flushing
## NAME
fflush - flush a stream
## SYNOPSIS
```
#include <stdio.h>
int fflush(FILE *fp);
```
## RETURN VALUE
Return : 0 if OK, EOF on error
## Description
* fp - 파일 포인터
* 라이브러리 버퍼의 내용을 해당 파일에 즉시 쓰게 하는 역할
* prompt처럼 '₩n'이 없는 문자열을 즉각 출력시키는데 유용
