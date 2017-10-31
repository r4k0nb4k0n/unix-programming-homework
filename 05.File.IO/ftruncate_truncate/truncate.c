/* 2017-2 Unix Programming
 * truncate example
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int ret;
	// If the value is given bigger than file size?
	// 파일의 크기가 커져 있다.
	ret = truncate("./test.txt", 30);
	if(ret == -1){
		perror("truncate");
		return -1;
	}
	return 0;
}
