# include <sys/epoll.h>
#include <stdio.h>
#define MAX_EVENTS 64
 
void main() {
	int ret, nr_events, i, epfd;
	struct epoll_event *events;
	struct epoll_event event;

	epfd = epoll_create(100);
	if (epfd<0) perror("epoll_create");

	event.data.fd = 0; //모니터할 fd 는stdin
	event.events = EPOLLIN | EPOLLOUT;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);
	if (ret<0) perror("epoll_ctl");

	events = malloc(sizeof(struct epoll_event) * MAX_EVENTS);
	if (!events) perror ("malloc");
					// 무한 타임아웃
	nr_events = epoll_wait(epfd, events, MAX_EVENTS, -1);
	if (nr_events<0) perror("epoll_wait");
	for (i=0; i<nr_events; i++){
		printf("event=%ld on fd=%d\n",
			events[i].events,
			events[i].data.fd);
	}
	close (epfd);
 	return 0;
}
