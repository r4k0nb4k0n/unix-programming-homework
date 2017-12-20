# 프로세스에 대한 대기(wait)
## NAME
`wait` - wait for process termination
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *statloc);
```
## RETURN VALUE
Return: child process ID if OK, `0` or `-1` on error
## Description
* `statloc` - 종료된 프로세스의 상태값 저장, 매크로 지원
![statloc](./statloc.png?raw=true)
* 자식 프로세스가 여럿인 경우 그 중 하나만 종료해도 리턴한다.
* 부모 프로세스에 발생한 시그널에 의해서도 리턴될 수 있다.
* 자식 프로세스가 없는 경우에는 `1`을 리턴
## 종료 상태 값
* `statloc`에 대한 매크로 함수
![statloc_macro](./statloc_macro.png?raw=true)

