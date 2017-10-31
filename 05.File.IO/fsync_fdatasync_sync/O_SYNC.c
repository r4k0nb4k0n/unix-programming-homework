#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char *fname = "test.txt";
	int fd;
	char *c, *buf = "This is test";

	fd = open(fname, O_WRONLY | O_SYNC);
	if( fd < 0 ){
		perror("open()");
		exit(-1);
	}
	for(c=buf;*c!='\0';c++){
		write(fd, c, 1);
	}
	close(fd);
	return 0;
}
