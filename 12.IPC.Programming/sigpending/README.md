# sigpending function
## NAME
signal handling functions
## SYNOPSIS
```c
#include <signal.h>

int sigpending(sigset_t* set);
```
## RETURN VALUE
Return: `0` if OK, `-1` on error.
## Description
* 호출된 프로세스에 대해 발생한 후 블록되어 있는 시그널 집합을 리턴
* 블록된 시그널 집합은 시그널 세트로 표현
* 중복 발생된 시그널은 누적되지 않음
