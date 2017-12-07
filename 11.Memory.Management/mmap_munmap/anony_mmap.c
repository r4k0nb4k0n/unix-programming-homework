#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int main(void) {
    char *p;
	int ret;

	p = mmap(NULL, 512*1024, PROT_READ|PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (p == MAP_FAILED)
		perror ("mmap");

	strcpy(p, "HELLO");
	printf("%s\n", p);

	ret = munmap(p, 512*1024);
	if (ret)
		perror("munmap");

	return 0;
}
