# File Masking
## NAME
`umask` - It determines the settings of a mask that controls how file permissions are set for newly created files.
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys.stat.h>
mode_t umask(mode_t cmask);
```
## RETURN VALUE
Return : previous file mode creation mask
## Description
* `umask`값을 프로세스 내에서 일시적으로 변경시키는 역할 수행
* 프로세스 내에서 변경된 `umask`값은 프로세스가 종료할 때까지만 유효
* `umask`
	* 파일 접근모드 생성 마스크
	* 보통 로그인 초기파일에 지정
	* `/etc/bashrc`에서 `umask`값 수정 가능
	* 생성되는 파일 접근권한 = `mode & ~umask & 01777`
