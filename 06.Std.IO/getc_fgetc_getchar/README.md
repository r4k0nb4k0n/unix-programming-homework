# 문자 단위 입력
## NAME
getc, fgetc, getchar - read one character at a time
## SYNOPSIS
```
#include <stdio.h>
int getc(FILE *fp);
int fgetc(FILE *fp);
int getchar(void);
```
## RETURN VALUE
Return : next character if OK, EOF on end of file or error
## Description
* 지정된 파일에서 한 문자씩 읽어들임
* fgetc()는 함수
* getc()는 매크로로 구현
* getchar()은 fgetc(stdin)
* 리턴 : 모든 문자값 + 에러(EOF 등)
