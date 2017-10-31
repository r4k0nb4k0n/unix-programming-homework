/* 2017-2 Unix Programming
 * read function. Process vs File Descriptor (2)
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	int fd;
	char c;
	
	if( (fd = open("test.txt", O_RDONLY)) < 0 ){
		perror("open");
		exit(0);
	}

	while(read(fd, &c, 1) > 0){
		putchar(c);
	}
	read(0, &c, 1);
	return 0;
}
