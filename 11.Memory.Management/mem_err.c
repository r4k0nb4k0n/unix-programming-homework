#include <stdio.h>

int main(void)
{
	char *greeting = "Hello World";
	char *c = &greeting[1];
	unsigned long badnews = *(unsigned long*)c;

	printf("%ld\n", badnews);

	return 0;
}
