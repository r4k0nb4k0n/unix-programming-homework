# `exec`을 위한 프로세스의 생성(vfork)
## NAME
`vfork` - create a child process
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>
pid_t vfork();
```
## RETURN VALUE
Return : Parent - Process ID of Child
         Child  - `0`, `-1` on error
## Description
* `exec` 함수를 통해 새 프로그램을 실행시킬 목적으로 자식 프로세스를 생성
* 자식을 생성하는 것은 `fork`와 동일하나 새로운 자식 프로세스에게 부모의 메모리와 제어권을 모두 넘김
* 자식 프로세스가 부모 프로세스의 메모리에서 실행되고 있는 동안 부모 프로세스는 block됨
* 자식에게 우선권 줌
* 자식 프로세스가 `_exit()` or `exec`을 호출한 후 부모의 수행이 재개됨
* 부모의 표준 입출력을 그대로 사용하고 있으므로 자식 프로세스를 `exit()`로 종료해서는 안됨(`_exit()` 호출)
## vfork() 정리
* `vfork()`을 사용하면 매우 빠른 속도로 프로세스를 생성할 수 있음
	* 프로세스를 생성하기 위해 부모 프로세스로부터의 데이터 복사 생략 가능
* `vfork()`의 동작 과정
	* 내무적으로 자식 프로세스를 생성해놓고 자식 프로세스가 `exec`을 하거나 `_exit()`을 호출 안하면???
		* 실행 중 다른 코드에서 버그가 발생하거나 exec 수행 시 에러 발생하면???
		* 부모 프로세스는 무한 대기


