# ungetc function
## NAME
ungetc - pushes c back to stream
## SYNOPSIS
```
#include <stdio.h>
int ungetc(int c, FILE *stream);
```
## RETURN VALUE
Return : c if OK, EOF on error
## Description
* c - 되돌려질 문자
* fp - 파일 포인터
* 지정된 문자를 입력 스트림에 되돌려 놓음
* 되돌려진 문자는 다음 fgetc, getc, getchar()이 호출될 때 다시 읽힘
	* 실제 파일에 되돌려진 문자가 기록되지는 않음
* 특정 조건을 검사하기 위해 하나의 문자를 읽은 후 원래의 상태로 복원하기 위해 이용
	* 같은 문자일 필요는 없음
* EOF 문자를 되돌릴 수는 없으나 EOF를 만난 경우 새로운 문자를 되돌릴 수는 있다
