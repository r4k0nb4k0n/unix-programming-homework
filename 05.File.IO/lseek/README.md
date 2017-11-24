# lseek function
## NAME
`lseek` - reposition read/write file offset
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fildes, off_t offset, int whence);
```
## RETURN VALUE
Return: new file offset if OK, -1 on error
## Description
* `offset` : 기준점에서의 상대적 거리  
	* 음수도 가능 (`SEEK_CUR`, `SEEK_END`)  
* `whence` : `offset` 지정시의 기준점  
	* `SEEK_SET`: 파일의 시작  
	* `SEEK_CUR`: 파일의 현재  
	* `SEEK_END`: 파일의 끝  
* 파일의 `offset`  
	* System file table에 위치함  
	* 파일을 처음부터 byte 단위로 계산한 정수값  
	* 기본적으로 파일이 열리면 `offset`의 위치는 `0`(`O_APPEND` 예외)  
	* **파일의 크기보다 큰 값으로 설정하면?**
## Screenshots
![lseek_1.success](./lseek_1.success.png?raw=true "lseek_1.success")  
파일의 offset을 파일의 크기(0 byte)보다 큰 값인 5로 설정해본 결과:  
![lseek_1.offset](./lseek_1.offset.png?raw=true "lseek_1.offset")
