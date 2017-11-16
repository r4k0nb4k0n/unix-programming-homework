#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){
	char *path;
	DIR* dp;
	struct dirent* dentry;
	struct stat buf;
	char *ptr;
	if(argc==1) path = ".";
	else if(argc==2){ path = argv[1]; chdir(argv[1]);}
	else{
		printf("usage: my_ls dirname\n");
		exit(1);
	}
	if(!(dp=opendir(path))){
		printf("opendir error.\n");
		exit(2);
	}
	while(1){
		dentry = readdir(dp);
		if(!dentry) break;
		if(!strcmp(dentry->d_name,".") || !strcmp(dentry->d_name, ".."))
			continue;
		if(lstat(dentry->d_name, &buf) < 0){
			perror("lstat()"); continue;
		}
		if(S_ISDIR(buf.st_mode)) printf("d");
		else if(S_ISREG(buf.st_mode)) printf("-");
		else if(S_ISLNK(buf.st_mode)) printf("l");
		
		if(S_IRUSR & buf.st_mode) printf("r");
		else printf("-");
		if(S_IWUSR & buf.st_mode) printf("w");
		else printf("-");
		if(S_IXUSR & buf.st_mode) printf("x");
		else printf("-");
		if(S_IRGRP & buf.st_mode) printf("r");
		else printf("-");
		if(S_IWGRP & buf.st_mode) printf("w");
		else printf("-");
		if(S_IXGRP & buf.st_mode) printf("x");
		else printf("-");
		if(S_IROTH & buf.st_mode) printf("r");
		else printf("-");
		if(S_IWOTH & buf.st_mode) printf("w");
		else printf("-");
		if(S_IXOTH & buf.st_mode) printf("x");
		else printf("-");
		printf(" %10lu %s\n", buf.st_size, dentry->d_name);
	}
	
	closedir(dp);
	return 0;
}
