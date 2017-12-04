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
	* `void*`는 캐스팅 할 필요 없음
	* 캐스팅 시 위험 초래 가능성
		1. 함수의 리턴 값이 `void*`가 아닐 경우 오류를 숨김
			* `malloc` 사용 시에는 위험하지 않음
		2. 함수를 적절하게 선언하지 않은 경우 버그를 감춤
			* 함수가 선언되지 않을 때 C언어는 기본적으로 int 타입이라 가정
* 에러를 내부적으로 처리하는 `xmalloc()` 함수
	* 아래 함수 사용 권장
	```c
	void* xmalloc(size_t size)
	{
		void* p;
		p = malloc(size);
		if(!p){
			perror("xmalloc");
			exit(1);
		}
		return p;
	}
	```
