# 비트 연산 실습 1
* `unsigned int` 변수에 플래그 설정 예제
* 다음의 매크로 이용
  * `#define OPEN    1`
  * `#define READ    2`
  * `#define WRITE   4`
  * `#define LSEEK   8`
  * `#define CLOSE  16`
* `main()`안에 `unsigned int flag` 변수 선언할 것
* 아래의 함수 작성
  * `clear_flag(unsigned int* p_flag, unsigned int opt)`
    * `p_flag` 변수에다가 인자로 넘어온 `opt`비트 클리어
    * ex) `clear_flag(&flag, WRITE | CLOSE)`
  * `set_flag(unsigned int* p_flag, unsigned int opt)`
    * `p_flag` 변수에다가 인자로 넘어온 `opt`비트설정
    * ex) `set_flag(&flag, OPEN | WRITE | CLOSE);`
  * `print_flag(&unsigned int flag)`
    * `flag`에 설정되어있는 옵션들을 출력
* [practice_1.c](./practice_1.c)
