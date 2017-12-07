# 스택에서 메모리 할당
## NAME
`alloca` - memory allocation from stack
## SYNOPSIS
```c
#include <alloca.h>
void* alloca(size_t size);
```
## RETURN VALUE
Return: Not `NULL` if OK, `NULL` on error
## `alloca.c`
* [alloca.c](./alloca.c)
* 스택 회수는 함수가 리턴할 때.
