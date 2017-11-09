#include <stdio.h>
int main(int argc, char **argv){
	int fd;

	if( argc != 3 ){
		printf("usage: link_1 existfile newfile\n");
		exit(1);
	}

	if( link(argv[1], argv[2]) < 0){
		printf("link call error\n");
		exit(2);
	}

	return 0;
}
