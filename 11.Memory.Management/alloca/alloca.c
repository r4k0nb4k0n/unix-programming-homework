#include <stdio.h>
#include <alloca.h>
#include <string.h>

int main(void) {
	const char *etc = "/etc/";
	const char *file = "passwd";
	char *name;

	name = alloca(strlen(etc)+strlen(file) + 1);
	strcpy(name, etc);
	strcat(name, file);

	printf("%s", name);

	return 0;
}
