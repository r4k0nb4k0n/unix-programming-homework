# 비트 연산 실습 3
* `unsigned int`형 변수를 인자로 넘겼을 때, 상위 `10`비트는 두 번째 인자, 중간 `10`비트는 세 번째 인자, 마지막 `12`비트는 네 번째 인자에 들어가도록 하는 함수를 작성하라.
  * `void div_num(unsigned int num, int *first, int *sec, int *third)`
  * 첫 번째 인자를 `0x29387200`으로 넘겼을 경우
    * first: `164`
    * second: `903`
    * third: `512`
* [practice_3](./practice_3.c)
