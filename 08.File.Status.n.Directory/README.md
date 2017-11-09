# 08. 파일 상태 및 디렉토리
## Linux File의 특징
* stat 구조체
	* ```#include <types.h>```
	```
	struct stat{
		mode_t st_mode; // file type * permission
		ino_t st_ino;
		nlink_t st_nlink; // link count
		uid_t st_uid;
		gid_t st_gid;
		dev_t st_dev;
		dev_t st_rdev;
		off_t st_size;
		time_t st_atime; // last access
		time_t st_mtime; // last modification
		time_t st_ctime; // last file status change
		long st_blksize;
		long st_blocks;
	};
	```
	시스템에 따라서 약간의 차이 존재 가능  
* 파일 형태
	* 정규파일(Regular File)
		* 데이터를 포함하는 가장 일반적인 파일 형태
		* Text or Binary인지를 커널은 구분하지 않고 다만 어플리케이션의 책임
	* 디렉토리 파일(Directory File)
		* 파일의 이름과 해당파일의 정보를 가지고 있는 곳을 가리키는 포인터로 구성
	* 블록 특수파일(Block Special File)
		* 시스템에 장착된 장치를 가리키는 파일로, I/O 수행시 일정 크기 데이터 전송
	* 문자 특수파일(Character Special File)
		* 시스템에 장착된 장치를 가리키는 파일로, I/O 수행시 일정 크기 데이터 전송
	* FIFO(Block Special File)
		* IPC 메커니즘의 일종으로 프로세스간 통신에 사용(일명 Named Pipe).
	* 심볼릭 링크(Symbolic Link File)
		* 다른 파일을 가리키는 포인터 역할하는 파일
	* 소켓(Socket)
		* 네트워크를 통한 프로세스간 통신에 사용되는 파일
* st_mode
	* 파일 형태를 검사하는 매크로 기능
	* 해당 종류의 파일이면 1, 아니면 0을 리턴
	```
	S_ISREG(mode) : 정규 파일
	S_ISDIR(mode) : 디렉토리 파일
	S_ISCHR(mode) : 문자 특수 파일
	S_ISBLK(mode) : 블록 특수 파일
	S_ISFIFO(mode) : pipe 또는 FIFO
	S_ISLNK(mode) : 심볼릭 링크
	S_ISSOCK(mode) : 소켓
	```
* 파일 접근 허가 모드 (permission)
	* 파일의 permission
	* 디렉토리 permission
		* Read : 디렉토리 안에 들어있는 파일의 이름을 읽을 수 있도록 함
		* Write : 디렉토리에 파일을 생성, 제거할 수 있도록 함
		* Execution : 해당 디렉토리 이하에 있는 파일을 접근하는 통로를 열어주는 역할
* effective user id, effective group id
* 스티키 비트 (Sticky Bit)
* 파일의 시간 정보
## File Status
[stat_fstat_lstat](./stat_fstat_lstat)
