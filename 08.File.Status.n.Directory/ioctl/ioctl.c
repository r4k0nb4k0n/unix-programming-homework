#include <stdio.h>
#include <unistd.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{	
	int   fd, ret;

	if (argc < 2) return 1; /* Error */
	fd  = open(argv[1], O_RDONLY | O_NONBLOCK);
	if (fd < 0) return 1; /* Error */
	ret = ioctl(fd, CDROMEJECT, 0);
	if (ret) return 1; /* Error */
	ret = close (fd);
	if (ret) return 1; /* Error */
	return 0;
}
