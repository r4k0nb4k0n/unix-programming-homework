#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd, len;
	char buf[20];
	if( (fd = open("tempfile", O_RDWR | O_CREAT | O_TRUNC, 0666)) < 0 ) {
		perror("open error");
		exit(-1);
	}

	unlink("tempfile");

	if( write(fd, "How are you?", 12) != 12) {
		perror("write error");
		exit(-1);
	}
	lseek(fd, 0L, SEEK_SET);
	if( (len = read(fd, buf, sizeof(buf))) <= 0 ) {
		perror("read error\n");
		exit(-1);
	}
	else buf[len] = '\0';
	printf("%s\n", buf);
	close(fd);

	if( (fd = open("tempfile", O_RDWR)) < 0 ) {
		perror("Second open error\n");
		exit(-1);

	}
	else
		close(fd);

	return 0;
}
