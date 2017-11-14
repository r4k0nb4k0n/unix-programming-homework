#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	if(open("before.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777) < 0){
		printf("1st open call error\n");
		exit(1);
	}
	umask(077);

	if(open("after.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777) < 0){
		printf("2nd open call error\n");
		exit(1);
	}
	return 0;
}
