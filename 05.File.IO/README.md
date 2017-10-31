# 05. File Input and output
System Call I/O  

### 리눅스 파일의 허가 모드
![ls](./ls.png?raw=true "ls")  
* USER/GROUP/OTHER로 권한이 나뉨  
  * r: 읽기 권한  
  * w: 쓰기 권한  
  * x: 실행 권한  

### System Call vs. Standard Library
![system_call](./system_call.png?raw=true "system_call")

### 여러 함수들 
* [에러 처리](./perror_stderror "에러 처리")
* [open function](./open "open function")
* [creat function](./creat "creat function")
* [close function](./close "close function")
* [lseek function](./lseek "lseek function")
* [read function](./read "read function")
* [write function](./write "write function")
* [Process vs. File Descriptor](./read/README.md "Process vs. File Descriptor")
* [pread, pwrite](./pread_pwrite "pread, pwrite")
* [fsync, fdatasync, sync](./fsync_fdatasync_sync "fsync, fdatasync, sync")
* [O_SYNC Flag](./fsync_fdatasync_sync/README.md "O_SYNC Flag")
* [ftruncate, truncate](./ftruncate_truncate "ftruncate, truncate")
* [dup, dup2](./dup_dup2 "dup, dup2")
* Multiplexed I/O:
  * [select](./select "select")
  * [pselect](./pselect "pselect")
  * [poll](./poll "poll")
  * [ppoll (Linux Only)](./ppoll "ppoll")

### 커널 내부
##### Virtual File System
* 공통 파일 모델(Common File Model)
  * 리눅스에서 모든 파일 시스템이 따라야 하는 framework
    * 읽기, 쓰기, 링크 생성 등 파일 시스템이 정의해야 하는 인터페이스 제공
    
