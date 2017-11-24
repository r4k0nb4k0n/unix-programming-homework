# creat function
## NAME
`creat` - create a file or device
## SYNOPSIS
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int creat ( const char *pathname, mode_t mode );
```
## RETURN VALUE
Return : file descriptor if OK, -1 on error
## Description
* `pathname` : 생성 파일 경로  
* `mode` : 생성 파일의 허가 모드  
	* `umask` 값과 연산하여 permission 결정  
  
* `default`로 write only로 생성 됨(Read 필요 시 파일을 다시 open 해야 함)
* `open( pathname, O_WRONLY | O_CREAT | O_TRUNC, mode )` 와 동등

**umask shell command로 현재 umask 확인 가능**  
**default umask 값은 /etc/bashrc에서 확인 가능**   

## Screenshots
![creat_1.success](./creat_1.success.png?raw=true "creat_1.success")
