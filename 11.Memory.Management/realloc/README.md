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
* `size`: 새롭게 변경될 크기
* `size`에 따른 메모리 할당
	* `size < previous size`
		* 리턴 값이 `ptr`과 같을 확률이 매우 높고 내부적으로도 큰 오버헤드 없이 할당 가는ㅇ
	* `size > previous size`
		* 리턴 값이 `ptr`과 달라질 수 있고, 내부적으로도 큰 오버헤드 발생 가능성
		* 메모리가 부족하면 새로운 곳에 기존의 내용을 복사해야 함
	* `size == 0`
		* 할당되었던 메모리를 해제

