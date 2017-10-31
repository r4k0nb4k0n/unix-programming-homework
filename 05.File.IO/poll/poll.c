/* 2017-2 Unix Programming
 * poll example
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5

int main(void){
	struct pollfd fds[2];
	int ret;

	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;

	fds[1].fd = STDOUT_FILENO;
	fds[1].events = POLLOUT;

	ret = poll(fds, 2, TIMEOUT * 1000);

	if(ret == -1) return 1; /* poll error */
	else if(!ret) return 0; /* timeout */

	if(fds[0].revents * POLLOUT){
		printf("stdout is writable\n");
	}
	return 0;
}
