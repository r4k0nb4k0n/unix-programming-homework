# 프로세스의 생성(fork)
## NAME
`fork` - create a child process
## SYNOPSIS
```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork();
```
## RETURN VALUE
Return  
* Parent - Process ID of Child
* Child - 0, -1 on error
## Description
* UNIX 운영체제에서 사용자가 새로운 프로세스를 생성할 수 있는 유일한 방법
* `fork()`를 호출한 프로세스를 Parent 프로세스라 부르고 새로 생성된 프로세스를 Child 프로세스라고 부름
* `fork()` 호출 다음부터 Parent와 Child가 프로세스가 동시 수행
* Kernel의 동작
	* 1. 새로운 프로세스를 위해 프로세스 테이블 항을 할당
	* 2. 자식 프로세스에게 고유의 ID 번호 부여
	* 3. 부모 프로세스의 내용을 복사 및 공유(텍스트, 데이터, 스택)
	* 4. 프로세스와 관련된 file table과 inode table 카운터를 증가
	* 5. 부모 프로세스에게는 자식의 ID를 리턴하고, 자식에게는 0을 리턴
* 실행전
![before_fork()](./before_fork1.png?raw=true)
* 실행후
![after_fork()](./after_fork1.png?raw=true)
* [fork function](./fork0.c)
* `fork()`를 통해 상속되는 속성
  * 실제
* Parent 프로세스와 달라지는 속성
* [fork()와 변수](./fork1.c)
* [fork()와 파일](./fork2.c)
	* Before fork
	![before fork](./before_fork2.png?raw=true)
	* After fork
	![after fork](./after_fork2.png?raw=true)
* [fork() 제어 구문](./fork3.c)
