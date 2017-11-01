#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main(void)
{
    char foo[15], bar[16], baz[17];
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;

    fd = open("animal.txt", O_RDONLY);
    if (fd == -1) return 1; /* perror(¡°open¡±); */
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof(foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[2].iov_len = sizeof(baz);

    nr = readv(fd, iov, 3);
    if (nr == -1) return 1; /* perror(¡°readv¡±); */
    for (i = 0; i < 3; i++) {
        printf("%d: %s", i, (char *) iov[i].iov_base);
    }
    if (close(fd)) return 1; /* perror(¡°close¡±); */
    return 0;
}
