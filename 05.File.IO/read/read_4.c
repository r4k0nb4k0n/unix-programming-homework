/* 2017-2 Unix Programming
 * read function. Process vs File Descriptor (2)
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	int fd, linecnt = 0;
	char c;
	char *fname = "test.txt";

	if( (fd = open(fname, O_RDONLY)) < 0 ){
		perror("open()");
		exit(-1);
	}
	while( read(fd, &c, 1) > 0 ){
		putchar(c);
		if( c == '\n' )
			linecnt++;
	}
	printf("Total line: %d\n", linecnt);
	read(0, &c, 1);
	return 0;
}
