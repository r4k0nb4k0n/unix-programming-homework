# 11. 메모리 관리
## 메모리
* 프로세스에서 사용 가능한 자원 중에서 가장 기본적이면서 핵심이 되는 자원
* 할당, 조작, 해제 등의 메모리 자원 기법 설명
* 여기서 말하는 메모리는 컴퓨터 시스템에 장착되어 있는 RAM을 뜻함.
## 프로세스 주소 공간
* 각 프로세스는 독립적인 크기의 가상 주소 공간을 가짐
	* 32bit 컴퓨터의 경우 `2^32` 바이트 만큼의 주소 공간 가짐
* 페이지(Page)
	* 가상 주소 공간의 기본 구성 요소
	* 보통 `4KB` or `8KB`. (CPU에 따라 크기를 임의로 설정할 수 있음)
	* 유효 페이지와 유효하지 않은 페이지로 나뉨
* 페이지 프레임(Page Frame)
* 페이지 테이블(Page Table)
![process-address-space](./process_address_space.png?raw=true)
## Share, Copy-On-Write
![share, copy-on-write](./share_copy_on_write.png?raw=true)
## 메모리 영역
![memory area](./memory_area.png?raw=true)
## 메모리 관련 함수들
* [동적 메모리 할당하기](./malloc)
* [배열 할당하기](./calloc)
