# Mapping Files into Memory
## NAME
mmap - map files into memory address space
## SYNOPSIS
```
#include <mman.h>
void* mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
```
## RETURN VALUE
Return: Not MAP_FAILED if OK, MAP_FAILED on error

## Description
* addr
  * 해당 시작 주소를 커널에게 선호한다고 알림
  * 불가능 시 또는 NULL일 경우 커널에서 임의로 할당
* len
  * 매핑될 영역의 크기
* prot - 메모리 보호 정책
  * PROT_READ - 읽기 가능한 페이지
  * PROT_WRITE - 쓰기 가능한 페이지
  * PROT_EXEC - 실행 가능한 페이지
  * fd의 flag와 충돌이 나면 안됨 O_WONLY <-> PROT_READ
* flags
  * MAP_FIXED: 반드시 인자로 주어진 addr로 매핑을 해야 함
  * MAP_PRIVATE: 다른 프로세스나 파일에 영향을 미치지 않도록 함
  * MAP_SHARED: 동일한 파일을 사상한 모든 프로세스가 사상을 공유
* fd
  * 매핑될 파일의 디스크립터
* offset
  * 매핑될 파일의 시작 위치
![mmap](./mmap.png?raw=true "mmap")  
* Page Size
  * Page
    * 접근 권한과 동작 방식이 독자적으로 유지되는 메모리의 최소 단위
    * 메모리 사상을 이루는 기본 구성 블록
    * mmap()시 인자인 addr과 offset은 페이지 단위로 정렬되어야 함
      * Ex) Page가 4KB이면 addr과 offset은 4096의 배수가 되어야 함
  * Page 크기 얻는 방법
    1. long page_size = sysconf(_SC_PAGESIZE);
    2. int page_size = getpagesize();
    3. int page_size = PAGE_SIZE;
