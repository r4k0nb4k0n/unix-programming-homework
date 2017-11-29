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
## setuid, setgid, seteuid, setegid
* `setuid(uid_t new_uid); // setgid(gid_t new_gid);`
  * Root가 아닌 경우: 사용자의 euid를 new_uid로 바꿈
  * Root: uid, euid, saved-uid를 new_uid로 바꿈
* `setuid(uid_t new_uid); // setgid(gid_t new_gid);`
  * Root가 아닌 경우: 사용자의 euid를new_euid로 바꿈. 단 new_euid는 사용자의 uid또는 saved_uid중 하나이어야 함
  * Root: 사용자의 euid를 new_euid로 바꿈. 어떤 값도 가능
* Program 예
  * case 1
    ```
    1. suid 비트설정      // uid | euid | saved-uid
       프로그램 실행      // 1000|  0   |     0
    2. seteuid(1000);     // 1000| 1000 |     0
    3. seteuid(0);        // 1000|  0   |     0
    ```
  * case 2
    ```
    1. suid 비트설정      // uid | euid | saved-uid
       프로그램 실행      // 1000|  0   |     0
    2. setuid(1000);      // 1000| 1000 |   1000
    3. seteuid(0);        // 1000| 1000 |   1000
    ```
