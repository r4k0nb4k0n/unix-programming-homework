# kill function
## NAME
`kill` - terminate a process
## SYNOPSIS
```c
#include <sys/types.h>
#include <signal.h>

int kill(pid_t pid, int sig);
```
## RETURN VALUE
Return: `0` if OK, `-1` on error
## Description
* `sig` 인자
	- 시그널 번호
	- null signal(0)
		- 실제로 시그널을 보내지 않고 프로세스의 존재여부 파악
		- 프로세스 미 존재시 `-1` 리턴
* `pid` 인자
	- `pid > 0`: 프로세스 ID가 `pid`인 프로세스에게 시그널 전달
	- `pid == 0`: 호출한 프로세스와 같은 그룹 ID를 가지고 있는 모든 프로세스에게 전달
	- `pid < 0`: pid의 절대값에 해당하는 프로세스 그룹 ID를 가지고 있는 모든 프로세스에게 시그널을 전달

