#include <sys/inotify.h>
#include <stdio.h>
#include <stdio.h>
#include <utime.h>

int main(int argc, char **argv)
{
	struct utimbuf *timebuf = NULL;

	if( argc != 2 ) {
		printf("usage: utime_1 filename\n");
		exit(1);
	}

	if( utime(argv[1], timebuf) < 0 ) {
		printf("utime call error\n");
		exit(2);
	}

	printf("success\n");
	return 0;
}

