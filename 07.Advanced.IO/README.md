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
