#include <signal.h>

void sig(int sig) {
	printf("child die (%d)\n", getpid());
}

main() {
	signal(SIGINT, sig);
	pause();
}