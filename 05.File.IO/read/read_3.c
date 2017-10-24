/* 2017-2 Unix Programming
 * read function : Non-blocking read
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(void){
	int fd, nr;
	char c;
	char *fname = "/dev/tty";

	if( (fd = open(fname, O_RDONLY | O_NONBLOCK)) < 0 ){
		perror("open()");
		exit(-1);
	}
	for(;;){
		if( nr = read(fd, &c, 1) > 0 ){
			printf("%c\n",c);
			exit(0);
		}
		else if( nr == 0 ){
			if( errno == EINTR ) printf(".");
			if( errno == EAGAIN ) printf("*");
		}
		else break;
	}
	return 0;
}
