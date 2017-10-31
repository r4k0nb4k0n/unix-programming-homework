# read function
## NAME
read - read data from an open file
## SYNOPSIS
```
#include <unistd.h>
ssize_t read(int filedes, void *buf, size_t nbytes);
```
## RETURN VALUE
Return: number of bytes read. 0 if end of file, -1 on error.
## Description
* buffer : 파일로부터 데이터를 읽어들일 메모리 주소  
* nbyte : 읽어들일 데이터의 최대 byte 수  
* Return 값에 따른 대응 필요  
    * nbyte와 같으면 성공  
    * nbyte보다 작지만 0보다는 큰 값  
        * 시그널이 중간에 읽기 중단  
        * 읽는 도중 오류가 발생  
        * len 바이트를 읽기 전에 EOF 도달  
    * 0이면 EOF -> 파일의 끝에 도달  
    * 리턴 안됨 -> 읽을 데이터가 없음 (디바이스 파일의 경우 데이터가 입력될 때까지 프로세스 중단)  
    * -1 -> errno가 EINTR이나 EAGAIN이 아닌 다른 값. 심각한 오류.  
## Screenshots
read_1  
![read_1.success](./read_1.success.png?raw=true "read_1.success")  
read_1.multiplebytes  
![read_2.success](./read_1.multibytes.png?raw=true "read_1.multibytes")  
read_1.nonblocking  
![read_1.nonblocking](./read_1.nonblocking.png?raw=true "read_1.nonblocking")  
## Process vs. File Descriptor (1)
* 한 Process가 동일 파일을 2번 open하여 read?  
 * 
