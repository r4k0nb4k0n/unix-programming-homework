# Change Permission
## NAME
chmod, fchmod - change permissions of a file
## SYNOPSIS
```
#include <sys/stat.h>
#include <sys/types.h>
int chmod(const char *pathname, mode_t mode);
int fchmod(int filedes, mode_t mode);
```
## RETURN VALUE
Return : 0 if OK, -1 on error
## Description
* chmod
	* pathname : 파일 경로 이름
	* mode : 새로 설정할 permission, set-user-id, set-group-id, sticky 비트
* fchmod
	* filedes : 파일 디스크립터
	* mode : 새로 설정할 permission, set-user-id, set-group-id, sticky 비트
* 파일의 접근허가 모드를 변경하기 위해 사용
* 이러한 변경이 가능하기 위해서는 file 소유자와 유효사용자 ID가 같아야 한다.
* permission, set-user-ID bit, sticky bit의 변경 가능
