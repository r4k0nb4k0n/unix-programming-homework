# write function
## NAME
write - write data from an open file
## SYNOPSIS
```
#include <unistd.h>
ssize_t write(int filedes, const void *buf, size_t nbytes);
```
## RETURN VALUE
Return : number of bytes written if OK, -1 on error

## Description
* buffer : 데이터가 들어있는 메모리 주소  
* nbyte : 기록할 데이터의 byte 수  
* Return 값과 nbyte 값은 같아야 한다. (다르면 에러)  

## Screenshots
my_copy 구현  
![my_copy](./my_copy.png?raw=true "my_copy")
