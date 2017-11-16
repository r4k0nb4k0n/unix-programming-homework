// unsigned integer 변수 안에 존재하는 비트 중 (32 bit) 1인 비트의 개수 세기

#include <stdio.h>

int count_bit(unsigned int num){
	int i, bit = 1, count = 0;

	for(i=0;i<sizeof(num)<<3;i++,bit<<=1)
		if(num&bit)
			count++;
	
	return count;
}

int main(void){
	int i;
	int nums[] = {256, 1159, 82991, 7182, 882001 };

	for(i=0;i<5;i++)
		printf("bit count of %d: %d\n", nums[i], count_bit(nums[i]));

	return 0;
}
