#include <stdio.h>
#include <stdlib.h>

int main(void){
	char buf[BUFSIZ];

	setvbuf(stdout, buf, _IOLBF, BUFSIZ);
	// stdout도 버퍼를 새로 설정하면 Fully Buffered로 바뀜 
	// 따라서 setvbuf(stdout, buf, _IOLBF, BUFSIZ);로 바뀜
	printf("Hello,"); sleep(1);
	printf("Unix!"); sleep(1);
	printf("\n"); sleep(5);

	setvbuf(stdout, NULL, _IONBF, 0);
	sleep(1);
	printf("How "); sleep(1);
	printf("are "); sleep(1);
	printf("you?"); sleep(1);
	printf("\n"); sleep(1);

	return 0;
}
