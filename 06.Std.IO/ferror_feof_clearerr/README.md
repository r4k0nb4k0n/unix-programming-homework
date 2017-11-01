# Error Check
## NAME
ferror, feof, clearerr - check and reset stream status
## SYNOPSIS
```
#include <stdio.h>
int ferror(FILE *fp);
int feof(FILE *fp);
void clearerr(FILE *fp);
```
## RETURN VALUE
Return : nonzero if condition is true, 0 otherwise
## Description
* fp - 조사 대상의 파일 포인터
* 입력 함수가 어떤 원인에 의한 EOF 복귀인지를 확인하기 위해 사용
* 입출력 오류 발생 여부 : ferror
* 파일의 끝을 만났는지의 여부 : feof
* 오류나 파일의 끝을 나타내는 정보는 FILE 구조체의 _flags 필드에 저장
* feof()는 _flags 필드에서 _IOEOF, ferror()는 _IOERR 비트가 설정되어 있는지 검사
* clearerr 함수는 _flags 필드의 _IOEOF, _IOERR비트를 리셋
## Screenshot
* feof_1
![feof_1](./feof_1.png?raw=true "feof_1")
