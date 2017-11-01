# 고급 입출력
## Scatter-gather I/O
* Scatter-gather I/O (Vector I/O) 장점
	* 자연스러운 자료 처리
		* 분산된 자료를 손쉽게 입출력
	* 효율
		* 다수의 선형 입출력을 하나의 벡터 입출력 연산으로 처리
	* 성능
		* 하나의 시스템 호출로 다수의 선형 입출력을 처리
	* 원자성
		* 흩어진 자료 입출력 과정이 원자적으로 처리됨
[Readv, writev](./readv_writev "Readv, writev")
## I/O Multiplexing
* 상황 가정
	* 키보드의 입력을 기다리면서, 네트워크를 통해 데이터가 전달되는 것을 동시에 기다림
	* 이것이 가능할까???
* 위의 상황을 처리할 수 있는 방법
	* 스레드(thread) 사용
	* 다중 입출력 함수 사용
		* poll, select, epoll
* 동작 방법
![io_multiplexing](./io_multiplexing.png?raw=true "io_multiplexing")  

## Epoll interface
* [Epoll interface](./epoll "epoll")

## Epoll: Edge Trigger vs Level Trigger
* Level Trigger: Default Mode
* Edge Trigger
  * event.events = EPOLLIN | EPOLLOUT | EPOLLET;
  * ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
* Edge Trigger vs. Level Trigger
  1. 프로세스 p가 epoll로 fd 입력을 기다림
  2. fd에 100바이트 입력이 주어짐
  3. p가 꺠어나 50바이트 읽어감
  4. p가 epoll로 fd 입력을 기다림
    * Level trigger mode인 경우: p는 바로 꺠어남
    * Edge trigger mode인 경우: p는 추가 입력이 발생할 때까지 대기
## Mapping Files into Memory
* [mmap](./mmap "mmap")
* [munmap](./munmap "munmap")
* 장점
    * read(), write() 시스템 콜과 다르게 추가 복사를 방지할 수 있음
        * read()
            1. 파일 데이터를 커널 영역으로 읽음
            2. 커널에 존재하는 데이터를 유저 영역의 버퍼로 복사
        * write()
            1. 유저 영역의 버퍼 내용을 커널 영역으로 복사
            2. 커널의 데이터를 파일에 적음
    * 입/출력 시 문맥 전환이 발생하지 않음
    * 프로세스간 데이터 공유 수월
    * 포인터 조절만으로 영역 탐색 - lseek()이 필요하지 않음
* 단점
    * 메모리 사상의 크기는 페이지 단위의 정수배만 가능. 나머지 공간은 낭비됨
    * 프로세스가 메모리 사상과 관련 자료 구조를 만드는 것은 오버헤드가 발생
        * 큰 파일을 사상할 때는 주의 필요
* 기타 mmap 관련 함수들
    * mremap - 사상 크기 조절할 때 사용
    * mprotect - 사상 접근 권한 변경
    * msync - 입출력을 동기화 하기
    * madivse - 커널이 최적화할 수 있도록 힌트 제공
    * 자세한 내용은 교재 참고
## 입출력 스케줄러
* 디스크의 선응을 떨어뜨리는 주범
    * Seek time(탐색 시간)
    * 디스크는 seek time을 최소화하기 위해 인접한 디스크 블록은 같은 트랙 및 실린더에 배치함.
* 입출력 스케줄러
    * 디스크 탐색 시간을 최소화 하기 위함
    * 입출력의 순서를 조작함으로써 탐색 횟수와 서비스 시간을 최소화 함
* 입출력 스케줄러의 주요 역할
    1. 병합 - 인접한 요청들을 하나의 요청으로 변환
        * 5,6,7,8번 디스크 블록에 대한 쓰기(혹은 쓰기) 요청이 있을 경우, 이들을 하나의 쓰기 요청으로 변경시키면 (5~8번까지) 입출력 횟수를 1/4로 줄일 수 있음
    2. 정렬 - 입출력 요청을 오름차순으로 변경
        * 99, 12, 58, 33, 209, 182이 있을 경우 12, 33, 58, 99, 182, 209로 변경
        * 기아(starvation) 발생 가능
* 읽기 vs. 쓰기
    * 읽기는 일반적으로 요청 즉시 서비스 되어야 함
    * 쓰기는 일반적으로 버퍼 캐시에 데이터를 모아 놓고 한번에 처리
    * 입출력 처리에 대한 우선 순위는 ?? -> 여러가지가 있다
* 리누스 엘리베이터
    * 리눅스 2.4의 입출력 스케줄러
    * 엘리베이터의 동작을 응용하여 입출력 스케줄링을 함
    * 기아 상태 해결
        * 정해진 시간 이상 대기된 요청이 있을 때, 삽입/정렬 기능을 멈춰버림
* 리눅스 2.6의 입출력 스케줄러
    * 데드라인(Deadline)
    * 예측(Anticipatory)
    * CFQ(Complete Fair Queueing)
    * NOOP(NO OPeration)
## 사용자 영역에서의 입출력 최적화
* 사용자 영역에서의 최적화가 필요한 경우
    * 디스크 접근 속도는 매우 느리기 때문
    * 입출력 스케줄러만으로는 한계 존재
        * 무작위로 입출력을 할 경우 입출력 스케줄러가 최적의 성능을 발휘할 수 없음
* 최적화 방법
    * 전체 경로
        * 같은 디렉토리에 속할수록 물리적으로 인접할 확률이 높음
    * 아이노드 번호
        * 파일이 여러 개일 때, 아이노드 번호에 따라서 입출력을 정렬
        * 파일 i의 아이노드 번호 < 파일 j의 아이노드 번호이면 파일 i의 물리 블록 < 파일 j의 물리 블록
        * fstat(), stat(), lstat()을 통해 아이노드 번호를 알아낼 수 있음
    * 파일의 물리 디스크 블록
        * 실제 파일의 물리 번호를 알아내고 입출력을 스케줄링
        * ret = ioctl(fd, FIBMAP, &block)
            * block은 논리블록 번호이고 호출이 끝나면 물리 블록이 채워져 돌아옴
