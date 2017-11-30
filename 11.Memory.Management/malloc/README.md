# 동적 메모리 할당하기
## NAME
`malloc` - dynamic memory allocation
## SYNOPSIS
```c
#include <stdlib.h>
void* malloc(size_t size);
```
## RETURN VALUE
Return: Not `NULL` if OK, `NULL` on error
## Description
* 원하는 바이트 수 만큼을 `heap`으로부터 할당
* `malloc()`을 통해 리턴되는 값을 캐스팅하지 않는 것을 권장

