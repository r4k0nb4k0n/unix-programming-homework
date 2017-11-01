# 줄 단위 입력
## NAME
fgets, gets - input string at a time
## SYNOPSIS
```
#include <stdio.h>
char *fgets(char *buf, int n, FILE *fp);
char *gets(char *buf);
```
## RETURN VALUE
Return : buf if OK, NULL on end of file or error
## Description
* buf - 문자열 보관할 버퍼
* n - 버퍼의 크기
* fp - 입력할 파일의 포인터
* fgets
	* newline or EOF를 만날 때까지 파일로부터 읽어 버퍼에 저장
	* 문자열의 끝은 NULL로 채워짐
* gets
	* stdin으로부터 newline을 만날 때까지 문자를 읽어 버퍼에 저장
	* newline을 NULL로 대체하여 읽음
	* 버퍼의 크기를 사용자가 지정하지 못하기 때문에 문제의 소지 발생 가능
		* BOF(Buffer Overflow)
## Screenshot
* fputs_fgets  
![fputs_fgets](./fputs_fgets.png?raw=true "fputs_fgets")
