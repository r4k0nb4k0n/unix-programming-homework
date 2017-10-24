/* 2017-2 Unix Programming
 * read function
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	int fd, linecnt = 0, cnt;
	char c;
	char *fname = "test.txt";

	if( (fd = open(fname, O_RDONLY)) < 0 ){
		perror("open()");
		exit(-1);
	}
	while( (cnt = read(fd, &c, 1)) > 0 ){
		/* Here, cnt == 1 */
		if( c == '\n' ) linecnt++;
	}
	printf("Total line: %d\n", linecnt);
	return 0;
}
