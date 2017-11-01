# 문자 단위 출력
## NAME
putc, fputc, putchar - output one character at a time
## SYNOPSIS
```
#include <stdio.h>
int putc(int c, FILE *fp);
int fputc(int c, FILE *fp);
int putchar(int c);
```
## RETURN VALUE
Return : c if OK, EOF on error
## Description
* 지정된 파일에 한 문자를 쓰는 기능
* fputc()는 함수
* putc()는 매크로
* putchar(c)은 fputc(c, stdout)
