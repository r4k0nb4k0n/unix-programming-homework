# 프로세스 식별자 (Process ID)
## NAME
`getpid` - return process ID of calling process
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
```
## RETURN VALUE
Return : Process ID
## Description
* 모든 프로세스는 음이 아닌 정수인 유일한 프로세스 ID를 가짐
* `getpid()` : 호출한 프로세스의 프로세스 ID 리턴
* `getppid()` : 호출한 프로세스의 부모 프로세스 ID 리턴
* `getuid()` : 호출한 사용자의 프로세스의 real user 리턴
* `geteuid()` : 호출한 사용자의 effective user ID 리턴
* `getgid()` : 호출한 프로세스의 real group ID 리턴
* `getegid()` : 호출한 프로세스의 effective group ID 리턴
