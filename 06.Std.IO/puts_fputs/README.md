# 줄 단위 출력
## NAME
puts, fputs - output one string at a time
## SYNOPSIS
```
#include <stdio.h>
int fputs(const char *str, FILE *fp);
int puts(const char *str);
```
## RETURN VALUE
Return : nonnegative value if OK, EOF on error
## Description
* str - 출력할 문자열
* fp - 출력할 파일 포인터
* fputs
	* NULL로 끝나는 문자열을 스트림에 씀(NULL 제외)
	* newline을 추가하지 않음
* puts
	* NULL로 끝나는 문자열을 표준출력(stdout)에 씀(NULL 제외)
	* newline을 추가

