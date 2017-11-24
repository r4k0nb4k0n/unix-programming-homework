#include <stdio.h>
#define OPEN	1
#define READ	2
#define WRITE	4
#define LSEEK	8
#define CLOSE	16

void clear_flag(unsigned int *p_flag, unsigned int opt){
	*p_flag &= ~opt;
}
void set_flag(unsigned int *p_flag, unsigned int opt){
	*p_flag |= opt;
}
void print_flag(unsigned int flag){
	int i, bit = 1;
	char *str[] = {"open", "read", "write", "lseek", "close"};
	for(i=0;i<5;i++,bit<<=1)
		if(flag&bit)
			printf("%s option is set\n", str[i]);
	return;
}

int main(void){
	unsigned int flag = 0;

	set_flag(&flag, OPEN | READ | LSEEK);
	print_flag(flag);
	clear_flag(&flag, READ | LSEEK);
	print_flag(flag);

	return 0;
}
