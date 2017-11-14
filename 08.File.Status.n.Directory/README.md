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
	* 시스템에 따라서 약간의 차이 존재 가능  
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
	| st_mode mask | Meaning |  
	|--------------|---------|  
	|S_IRUSR|user_read|  
	|S_IWUSR|user_write|  
	|S_IXUSR|user_execute|  
	|--------------|---------|  
	|S_IRGRP|group_read|  
	|S_IWGRP|group_write|  
	|S_IXGRP|group_execute|  
	|--------------|---------|  
	|S_IROTH|other_read|  
	|S_IWOTH|other_write|  
	|S_IXOTH|other_execute|  
	* 디렉토리 permission
		* Read : 디렉토리 안에 들어있는 파일의 이름을 읽을 수 있도록 함
		* Write : 디렉토리에 파일을 생성, 제거할 수 있도록 함
		* Execution : 해당 디렉토리 이하에 있는 파일을 접근하는 통로를 열어주는 역할
* effective user id, effective group id
	* Real user ID, real group ID
		* 프로세스를 실제로 실행시키고 있는 사용자의 ID
		* 로그인할 때 사용된 ID
	* Effective user ID, effective group ID
		* 파일에 대한 접근 권한을 결정
	* set-user-ID, set-group-ID 비트
		* 프로세스 실행 시, effective user ID값이 프로세스를 실행한 사용자의 ID(real user id)가 아니라 파일의 소유자 ID로 설정
		* S_ISUID, S_ISGID
	* 일반적인 프로그램 실행 시
		* Real user ID -> effective user ID
		* Real group ID -> effective group ID
	* 프로그램에 set-user-ID(S_ISUID), set_group-ID(S_ISGID) 비트 설정 시
		* file owner ID -> effective user ID
		* find group owner ID -> effective group ID
	* stat 구조체의 st_mode값과 AND 연산을 통해 비트 설정의 유무 확인 가능
		* S_ISUID(4), S_ISGID(4)
	* 보안에 유의 필요!
* 스티키 비트 (Sticky Bit)
	* 파일이 존재하는 디렉토리에 접근 권한이 있다 해도 파일 삭제는 파일의 소유자만 할 수 있도록 함
	* 공동 작업 디렉토리에서 여러 사용자가 작업할 경우 다른 사용자에 의해 파일이 삭제되는 것을 방지
	* S_ISVTX(1)
* 파일의 시간 정보
	* stat 구조체의 멤버 중에는 시간 값을 가지는 세 개의 멤버가 있음
	* 파일의 관리 및 보안에 이러한 시간 정보들이 유용하게 사용될 수 있음
	* st_atime
		* 파일의 데이터가 마지막으로 읽혔던 시간
		* read() 호출
	* st_mtime
		* 파일의 데이터가 마지막으로 변경된 시간
		* write() 호출
	* st_ctime
		* 파일의 stat 구조의 내용이 마지막으로 변경된 시간
		* link(), chmod(), write() 호출
## File Status
* [stat_fstat_lstat](./stat_fstat_lstat)

## 리눅스 디렉토리의 구조
* 디렉토리의 데이터
* 디렉토리 엔트리
## Link
* 이미 존재하는 파일이나 디렉토리의 연결을 의미
	* Windows의 단축 아이콘과 유사한 개념
* 링크의 두 가지 종류
	* 하드 링크 (Hard link)
	* 심볼릭 또는 소프트 링크 (Symbolic or soft link)
## Hard Link

## Hard Link vs. Symbolic Link
* Hard link
	* 장점
		* 파일로의 빠른 접근 가능
			* 디렉토리 엔트리 읽기 한번
			* 아이노드 읽기 한번
			* 데이터 블록 읽기 한번
	* 단점
		* 서로 다른 파일시스템 사이의 링크 불능
		* 디렉토리 링크 시 chain 발생 가능
		* 파일의 삭제를 보장할 수 없음
* Symbolic Link
	* Hard link의 단점을 모두 보완
	* 단점
		* 파일로 접근 시 상대적으로 많은 읽기 연산 필요
			* 디렉토리 엔트리 읽기 두번
			* 아이노드 읽기 두번
			* 데이터 블록 읽기 두번
## Link functions

