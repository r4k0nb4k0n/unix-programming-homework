#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

int fd[2];

void alarm_handler(int sig) {
	fcntl(fd[0], F_SETFL, O_NDELAY);
}

int main(void)
{
	char buf[100];

	signal(SIGALRM, alarm_handler);
	pipe(fd);
	alarm(3);
	read(fd[0], buf, 100);

	close(fd[0]);
	close(fd[1]);

	return 0;
}
