# sigprocmask function
## NAME
signal handling functions
## SYNOPSIS
```c
#include <signal.h>

int sigprocmask(int how, const sigset_t* set, sigset_t* oset);
```
## RETURN VALUE
Return: `0` if OK, `-1` on error
## Description
* `signalmask`를 변경하거나 검사한다.
	- `signalmask`: 프로세스에게 전달되지 않도록 블록된 시그널의 집합
* `how`: 시그널 set을 변경시키는 방법
	- `SIG_BLOCK`: set 인자로 지정된 시그널들을 시그널 마스크에 추가
	- `SIG_UNBLOCK`: set 인자로 지정된 시그널들을 시그널 마스크에서 제외
	- `SIG_SETMASK`: set 인자로 시그널 마스크를 대체
* `set`: 변경될 시그널 마스크
* `oset`: `sigprocmask` 함수 호출 이전의 시그널 마스크 내용
* `oset`이 `NULL`이 아니면 이전의 블록된 시그널 set 값이 저장
* `set`이 `NULL`이면 `how`는 의미가 없으면 기존 마스크 값을 얻기 위해 사용

