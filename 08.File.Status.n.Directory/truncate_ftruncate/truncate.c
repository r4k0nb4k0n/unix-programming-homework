#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{	
	if( truncate("trun.txt", 10) < 0 ) {
		perror("truncate error");
		exit(-1);
	}

	return 0;
}
