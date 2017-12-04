# 새로운 프로그램의 실행(`system`)
## NAME
`system` - execute a shell command
## SYNOPSIS
```c
#include <stdlib.h>

int system(const char* cmdstring);
```
## RETURN VALUE
Return: `-1`(fork fail), `127`(exec fail), return stat of sh
## Description
* `fork`, `exec`, `waitpid` 함수로 구성
* `fork`가 실패하거나 `waitpid`가 `EINTR` 이외의 값을 리턴하면, `system()`은 `errno` 값을 지정하고 `-1` 리턴
* `exec`이 실패한 경우에는 생성한 프로세스의 종료 상태 값으로 `127`을 리턴
* 세 함수가 모두 성공하면 `waitpid`로 얻어낸 쉘의 종료 상태 값을 리턴

