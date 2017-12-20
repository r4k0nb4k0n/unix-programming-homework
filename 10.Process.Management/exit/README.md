# 프로세스의 종료(exit)
## NAME
`exit` - terminate the current process
## SYNOPSIS
```c
#include <stdlib.h>
void exit(int status);

#include <unistd.h>
void _exit(int status);
```
## RETURN VALUE
Return : 
## Description
* `exit`
	* `status` : 종료 상태 값
	* 표준 입출력 정리 루틴을 수행한 후, `_exit()` 호출
	* open된 file stream에 대해 `fclose` 호출, 버퍼에 남은 데이터를 `flush`
* `_exit`
	* `status` : 종료 상태 값 (성공 종료면 `0`, 에러 발생 시 `0` 이외의 값)
		* system call
	* 자식의 종료 상태 정보는 부모에게 전달될 필요성이 있음.
	* `status`값은 하위 `8bit`만 사용됨(0~255)
* `int atexit(void (*function)(void));`
	* 종료할 때 자동으로 실행되도록 등록하는 함수
	* 최대 32개까지 등록할 수 있고 등록된 숫자 역순으로 함수 실행
## `exit` vs. `_exit`
* [exit1.c](./exit1.c)
* [exit2.c](./exit2.c)
## `atexit`
* [atexit.c](./atexit.c)

