#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main(void) {
    void *p;
	int ret, fd;

	fd = open("/dev/zero", O_RDWR);
	if (fd < 0) {perror("open"); return -1;}

	p = mmap(NULL, getpagesize(), PROT_READ|PROT_WRITE,
		MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED) {
		perror ("mmap");
		close(fd);
		return -1;
	}

	strcpy(p, "HELLO");
	printf("%s\n", p);

	ret = close(fd);
	if (ret)
		perror("close");

	return 0;
}
