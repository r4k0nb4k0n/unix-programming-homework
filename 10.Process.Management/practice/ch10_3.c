#include<stdio.h>

FILE *fp;


void func(void) {
	fclose(fp);
}


int main(void)
{	
	fp=fopen("a.txt","r");	
	char temp[255];

	if(fp==0) exit(3);

	while(fgets(temp, sizeof(temp),fp) != NULL) {
		printf("%s",temp);	
	}
	atexit(func);
	return 0;
}
