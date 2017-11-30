#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void func1(void) {
	printf("func1\n");
}

void func2(void) {
	printf("func2\n");
}

int main(void) {
	printf("hi.\n");
	atexit(func1);
	atexit(func2);
	printf("bye.\n");
	exit(0);
}
