# File Status
## NAME
`access` - check user's permissions for a file
## SYNOPSIS
```c
#include <unistd.h>
int access(const char *pathname, int mode);
```
## RETURN VALUE
Return : `0` if OK, `-1` on error
## Description
* `access`
	* pathname : 파일 경로 이름
	* mode : 검사하고자 하는 permission 값  
	![access_mode](./access_mode.png?raw=true)
	* real user ID와 real group ID에 대한 permission check

