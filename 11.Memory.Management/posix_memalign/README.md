# 정렬된 메모리 할당
## NAME
`posix_memalign` - allocate aligned memory
## SYNOPSIS
```c
#define _GNU_SOURCE
#include <stdlib.h>
int posix_memalign(void** memptr, size_t alignment, size_t size)
```
## RETURN VALUE
Return: `0` if OK, Not `0` on error
## Description
* `memptr`: 할당된 메모리의 시작 주소
* `alignment`: 정렬할 메모리의 크기
* `size`: 할당을 원하는 바이트 수
* 사용방법
```c
char* buf;
int ret;
ret = posix_memalign(&buf, 256, 1024);
if( ret ){
	//error
}
// 버퍼 사용
free(buf);
```
