# 할당 크기 조정
## NAME
`realloc` - resize allocated memory
## SYNOPSIS
```c
#include <stdlib.h>
void* realloc(void* ptr, size_t size);
```
## RETURN VALUE
Return: Not `NULL` if OK, `NULL` on error
## Description
* `ptr`: 크기가 변경될, 이미 할당된 메모리
*
