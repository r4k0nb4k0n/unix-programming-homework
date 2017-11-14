#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){
	struct stat statbuf;

	if(stat("before.txt", &statbuf)<0){
		perror("stat error for before.txt");
		exit(-1);
	}
	if(chmod("before.txt", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0){
		perror("chmod error for before.txt");
		exit(-1);
	}
	if(chmod("after.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0){
		perror("chmod error for after.txt");
		exit(-1);
	}
	return 0;
}
