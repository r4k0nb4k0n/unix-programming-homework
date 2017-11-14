# File Status
## NAME
access - check user's permissions for a file
## SYNOPSIS
```
#include <unistd.h>
int access(const char *pathname, int mode);
```
## RETURN VALUE
Return : 0 if OK, -1 on error
## Description
* access
	* pathname : 파일 경로 이름
	* mode : 검사하고자 하는 permission 값  
	| mode | Description |
	|------|-------------|
	|R_OK  |test for read permission|
	|W_OK  |test for write permission|
	|X_OK  |test for execute permission|
	|F_OK  |test for existence permission|
	* real user ID와 real group ID에 대한 permission check

