# Positioning a Stream
## NAME
ftell, fseek, rewind - reposition a stream
## SYNOPSIS
```
#include <stdio.h>
long ftell(FILE *fp);
int fseek(FILE *fp, long offset, int whence);
void rewind(FILE *fp);
```
## RETURN VALUE
Return :  
* ftell - current file position indicator if OK, -1L on error
* fseek - 0 if OK, nonzero on error
## Description
* ftell
	* 파일의 현재 offset을 돌려줌
* fseek
	* fp - 파일 포인터
	* offset - 위치
	* whence - offset 지정시의 기준 위치
		* SEEK_SET, SEEK_CUR, SEEK_END
* rewind
	* 파일의 offset을 처음으로 이동
## Screenshots
* ftell_1  
![ftell_1](./ftell_1.png?raw=true "ftell_1")
* fseek_1  
![fseek_1](./fseek_1.png?raw=true "fseek_1")
* rewind  
![rewind_1](./rewind_1.png?raw=true "rewind_1")
