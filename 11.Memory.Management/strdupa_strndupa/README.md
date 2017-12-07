# 스택에 문자열 복사
## NAME
`strdupa`, `strndupa` - string copy to stack memory
## SYNOPSIS
```c
// alloca() and strcpy()...
#define _GNU_SOURCE
#include <string.h>
char* strdupa(const char* s);
char* strndupa(const char* s, size_t n);
```
## RETURN VALUE
Return: Not `NULL` if OK, `NULL` on error
## 가변길이 지역변수
[var_length.c](./var_length.c)  
최신 컴파일러에서만 가능하다.
