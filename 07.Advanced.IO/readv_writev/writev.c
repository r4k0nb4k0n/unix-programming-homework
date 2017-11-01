#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

int main(void)
{
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    char *buf[] = {
         "I have a cat.\n",  "She has a dog.\n",
         "He likes a dog.\n"};

    fd = open("animal.txt", 
                 O_WRONLY | O_CREAT | O_TRUNC,  0666);
    if (fd == -1) return 1; /* perror(¡°open¡±); */
    for (i = 0; i < 3; i++) {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }

    nr = writev(fd, iov, 3);
    if (nr == -1) return 1; /* perror(¡°writev¡±); */
    printf("wrote %d bytes\n", nr);
    if (close(fd)) return 1; /* perror(¡°close¡±); */
    return 0;
}
