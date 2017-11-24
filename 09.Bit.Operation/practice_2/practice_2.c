#include <stdio.h>

int check_nth_bit(unsigned int num, int n){
	return (num >> (n-1)) & 1;
}
int invert_nth_bit(unsigned int num, int n){
	return check_nth_bit(num, n) ^ 1;
	// (~num >> (n-1)) & 1;
}
int main(void){
	unsigned int num = 16;
	int i;
	for(i=0; i<8;i++)
		printf("%d %d\n", check_nth_bit(num, i), invert_nth_bit(num, i));

	return 0;
}
