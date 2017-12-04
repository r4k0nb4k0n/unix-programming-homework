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
* `size`: 배열 원소의 크기
* `malloc(nr*size)`와 동일한 크기의 `0`으로 초기화된 메모리 할당
* `calloc` vs. `malloc` 후 메모리 내용을 `0`으로 초기화
	* `calloc`은 `0`으로 초기화된 메모리에서 할당하기 때문에 "`malloc` 후 `0`으로 초기화"하는 것보다 빠름.
## 배열 할당하기
* 에러처리 및 `0`으로 초기화된 메모리를 할당하는 `xmalloc0` 함수
```c
void* xmalloc0(size_t size)
{
	void* p;
	p = calloc(1, size);
	if(!p){
		perror("xmalloc0");
		exit(1);
	}
	return p;
}
```
