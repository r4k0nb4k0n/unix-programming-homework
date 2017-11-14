#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	DIR* dp;
	struct dirent* dentry;

	if(argc!=2){
		printf("usage: my_ls dirname\n");
		exit(1);
	}
	if(!(dp=opendir(argv[1]))){
		printf("opendir error.\n");
		exit(2);
	}
	while(1){
		dentry = readdir(dp);
		if(!dentry) break;
		printf("%s\n", dentry->d_name);
	}

	return 0;
}
