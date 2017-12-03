# Utime
## NAME
`utime` - change access and/or modification in the i-node
## SYNOPSIS
```c
#include <sys/types.h>
#include <utime.h>

int utime(const char* pathname, const struct utimbuf* times);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* pathname - 대상 파일 경로
* timebuf - utimebuf 구조체
```c
struct utime{
  time_t actime; // access time
  time_t modtime; // modification time
}
```
* 각 필드는 1970. 1.1 00:00부터 현재까지의 시간을 초로 환산한 값
* utimebuf 구조체가 `NULL`이면 파일의 최종 접근시간(st_atime), 최종 변경시간(st_mtime)은 현재 시간으로 변경
* utimebuf 구조체가 `NULL`이 아닌 경우 최종 접근시간은 actime으로 최종 변경 시간은 modtime으로 변경

