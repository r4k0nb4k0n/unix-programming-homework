# open function
## NAME
open - open or create a file or device
## SYNOPSIS
```
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open ( const char *pathname, int oflag);
int open ( const char *pathname, int oflag, mode_t mode);
```
## RETURN VALUE
Return : file descriptor if OK, - on error

## Screenshots
![open_1.fail](./open_1.fail.png?raw=true "open_1.fail")  
![open_1.success](./open_1.success.png?raw=true "open_1.success")  

## Description
* oflag : open의 목적  
   * O_RDONLY: 읽기 전용  
   * O_WRONLY: 쓰기 전용  
   * O_RDWR: 읽기, 쓰기 가능  
   * O_APPEND: 모든 쓰기 작업은 파일의 끝에서 수행된다.  
   * O_CREAT: 파일이 없을 경우 파일 생성  
   * O_DIRECT: 직접 입출력 수행 위해 파일을 연다.  
   * O_EXCL: O_CREAT시 파일이 있는 경우에 error 발생  
   * O_TRUNC: 파일이 있는 경우에 기존 파일을 지운다.  
   * O_NONBLOCK: blocking I/O를 nonblocking 모드로 바꿈  
   * O_SYNC: 매 쓰기 연산마다 디스크 I/O가 발생하도록 설정  
   
* mode : 파일의 접근권한  
   * 새로운 파일 생성시에만 사용(O_CREAT)  
