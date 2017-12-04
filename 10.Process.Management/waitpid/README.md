# 프로세스에 대한 대기(waitpid)
## NAME
`waitpid` - wait for process termination
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int* statloc, int options);
```
## RETURN VALUE
Return: child process ID if OK, `0` or `-1` on error
## Description
* pid
	* `==-1` : wait 함수와 동일한 기능
	* ` > 0` : 프로세스 ID가 pid인 프로세스의 종료 상태값을 리턴
	* `== 0` : 호출 프로세스와 같은 프로세스 그룹에 있는 자식 프로세스 중 어느 하나 종료시
* options
	* `WNOHANG` : `pid`인 프로세스가 종료되지 않았어도 바로 리턴(리턴 값 0)
	* `WUNTRACED` : `pid`인 프로세스가 잠시 중단된 경우에 리턴
		* `WIFSTOPPED` 매크로를 통해 확인
* 특정 자식의 종료 상태값을 얻을 수 있다.
* blocking을 방지할 수 있다.

