# 동적 메모리 해제하기
## NAME
`free` - free allocated memory
## SYNOPSIS
```c
#include <stdlib.h>
void free(void* ptr)
```
## RETURN VALUE
Return: None
## Description
* `malloc()`, `calloc()`, `realloc()`에 의해 할당된 메모리를 해제
* C언어에서는 할당한 메모리는 반드시 프로그래머가 해제해줘야 함
* 적절히 메모리 해제를 하지 못할 경우 메모리 누수 현상 발생
	* C언어에서 가장 흔한 버그 중 하나
* `ptr`이 `NULL`이더라도 상관없음.
	* `free()`하기 전에 `ptr`의 `NULL` 유무를 검사할 필요 없음.
## 프로그래밍 시 메모리 누수 방지 팁
Memory leakage
* `malloc()`, `calloc()`, `realloc()` 등의 메모리 할당을 하다보면 자연스레 프로그램의 버그가 많아짐
* 버그를 줄일 수 있는 방법
	* 가능한 한 동적 할당을 사용하지 않는 것이 좋음
	* 피할 수 없을 때에만 제한적으로 사용
