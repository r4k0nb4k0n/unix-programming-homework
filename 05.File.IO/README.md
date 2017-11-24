# 05. File Input and output
System Call I/O  

### 리눅스 파일의 허가 모드
![ls](./ls.png?raw=true "ls")  
* `USER/GROUP/OTHER`로 권한이 나뉨  
	* `r`: 읽기 권한  
	* `w`: 쓰기 권한  
	* `x`: 실행 권한  

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
		![vfs](./vfs.png?raw=true "vfs")  
* 장점  
	* 한가지의 시스템 호출 통해 어떤 매체에 있는 파일 시스템도 읽을 수 있음  
	* 유틸리티 하나로 서로 다른 파일시스템 사이에 복사 지원 가능 -> 읽기, 쓰기 가능  
	* 모든 파일 시스템은 동일한 개념, 동일한 인터페이스, 동일한 호출 지원  
	* 새로운 파일 시스템을 개발하더라도 리눅스에서 쉽게 사용 가능
##### Page Cache
* Locality of reference  
	* Spatial locality  
		* 현재 참조되는 자원과 인접한 곳에서 참조가 발생할 확률이 높음
	* Temporal locality  
		* 특점 시점에서 자원에 접근되면 그 자원은 다시 참조될 확률이 높음  
    ```c
	int num[10000], sum = 0, i;  
   	.....  
    for(i=0;i<10000;i++)  
        sum += num[i];  
    .....  
    ```
* 보조기억장치(e.g. HDD, USB Drive)와 메인 메모리 사이의 속도차를 완화시키기 위함
	* 가까운 미래에 참조될 것으로 판단되는 내용을 메인 메모리에 위치 시킴
* 리눅스 페이지 캐시
	* 동적인 크기를 지원
		* 적은 영역을 사용하다 점진적으로 증가하다가 최대 크기가 되었을 때 멈춤
		* 최대 크기가 되었을 때, 어떤 내용을 교체해야 할까?
	* 대표적인 교체정책
		* FIFO(FIrst In First Out), RANDOM, LRU(Least Recently Used), LFU(Least Frequently Used)  
* Hit ratio
	* cache hit count / total reference count
	* 높을 수록 좋은 캐시 교체 정책 알고리즘
* Read-ahead(prefetching)
	* 앞으로 접근될 것으로 판단되는  메인 메모리로 읽어 놓음
	* 미리 정해놓은 크기가 될 때 까지, 읽어오는 크기를 점진적으로 크기를 증가시킴
##### Page Writeback
* 페이지 캐시에 존재하는 내용 중 쓰인 내용(dirty page)을 다시 보조기억장치에 적는 일
* Page Writeback이 발생하는 상황
	* 미리 정의된 메모리 양보다 페이지 캐시의 여유 메모리 공간이 줄어들 때
	* 미리 정의된 시간보다 변경된 내용이 오래되었을 때
* `pdflush` (Page Dirty FLUSH)
	* 위의 두 조건 중 하나라도 만족되면 이 커널스레드가 꺠어나 page writeback 수행
* `pdflush`를 통해 데이터를 적기 전에 시스템이 꺼지면?
	* 데이터 날아감.

