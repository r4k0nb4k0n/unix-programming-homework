#include <stdio.h>
#include <string.h>

int main(void) {
	const char *etc = "/etc/";
	const char *file = "passwd";
	char name[strlen(etc) + strlen(file) + 1];

	strcpy(name, etc);
	strcat(name, file);

	printf("%s", name);

	return 0;
}
