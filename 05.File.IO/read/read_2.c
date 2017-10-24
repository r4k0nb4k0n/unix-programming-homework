/* 2017-2 Unix Programming
 * read function : read multiple bytes
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSIZE 2

int main(void){
	int fd, linecnt = 0, cnt, i;
	char c[BUFSIZE];
	char *fname = "test.txt";

	if( (fd = open(fname, O_RDONLY)) < 0 ){
		perror("open()");
		exit(-1);
	}
	while( (cnt = read(fd, &c, BUFSIZE)) > 0 ){
		for(i=0; cnt>0; i++, cnt--){
			if( c[i] == '\n' ) linecnt++;
		}
	}
	printf("Total line: %d\n", linecnt);
	return 0;
}
