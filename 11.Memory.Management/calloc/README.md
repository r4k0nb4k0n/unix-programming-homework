# 배열 할당하기
## NAME
`calloc` - memory allocation for dynamic size of an array
## SYNOPSIS
```c
#include <stdlib.h>
void* calloc(size_t nr, size_t size);
```
## RETURN VALUE
Return: Not `NULL` if OK, `NULL` on error
## Description
* `nr`: 배열 원소의 개수
* `size`: 배열 원소의 크긔

