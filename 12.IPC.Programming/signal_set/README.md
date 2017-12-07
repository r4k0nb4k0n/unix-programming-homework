# Signal set
## NAME
signal set handling
## SYNOPSIS
```c
#include <signal.h>

int sigemptyset(sigset_t* set);
int sigfillset(sigset_t* set);
int sigaddset(sigset_t* set, int signo);
int sigdelset(sigset_t* set, int signo);
int sigismember(const sigset_t* set, int signo);
```
## RETURN VALUE
Return: `0` if OK, `-1` on error(`sigismember`: `1` if true else `0`)
## Description
* `sigemptyset`
	- `set`의 모든 시그널을 `0`으로 set(모든 시그널 제외)
* `sigfillset`
	- `set`의 모든 시그널을 `1`로 set(모든 시그널 포함)
* `sigaddset`
	- `set`의 멤버로서 `signo`로 지정된 시그널 추가
* `sigdelset`
	- `set`에서 `signo`로 지정된 시그널 제거
* `sigismember`
	- `signo` 시그널이 `set`의 멤버인지 검사

