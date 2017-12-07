# Signal function
## NAME
`signal` - signal handling
## SYNOPSIS
```c
#include <signal.h>
typedef void (*sighandler_t) (int);
sighandler_t signal(int signo, sighandler_t handler);
```
## RETURN VALUE
Return: `-1` with errno set to `EINTR`
## Description
* 인자로 받은 시그널에 대한 액션을 정의
* Signal 무시
	- `signal(SIGINT, SIG_IGN);`
* Signal 복구(시그널 처리 시 기본 동작으로 되돌림)
	- `signal(SIGINT, SIG_DFL);`
* Signal 처리(catch)
	- 두 번째 인자로 미리 정해 놓은 함수(시그널 핸들러)의 포인터를 설정하면 시그널 발생 시, 해당 함수가 실행
	- 시그널 핸들러는 `void (*sighandler_t) (int)` 다음과 같이 정의됨
	- 리턴: `void`, 인자: `int`형 변수 한 개
* 여러 개의 시그널을 무시할 수도 있음
	- `signal(SIGINT, SIG_IGN);`
	- `signal(SIGQUIT, SIG_IGN);`

