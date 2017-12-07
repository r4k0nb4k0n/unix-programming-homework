# alarm function
## NAME
`alarm` - set an alarm clock for delivery of a signal
## SYNOPSIS
```c
#include <unistd.h>

unsigned int alarm(unsigned int second);
```
## RETURN VALUE
Return: `0` or number of seconds until previously set alarm
## Description
* 지정된 시간 후에 `SIGALRM` 시그널이 발생하도록 타이머 설정
* `SIGALRM`의 기본 처리 방법은 프로세스의 종료
* 일반적으로 시그널 처리 함수를 등록하여 사용
* 한 프로세스에는 하나의 알람만 존재
* 이미 알람이 설정된 상태에서 다시 `alarm()` 함수를 호출하면 이전 알람의 남은 시간이 리턴되고 새로운 알람으로 설정됨
* second 인자가 `0`인 경우, 이미 설정된 알람이 존재하면 남은 시간이 리턴되고 알람은 해제됨

