#include <stdio.h>
#include <stdlib.h>

int main(void){
	flockfile(stdout);
	fputs("List of treasure:\n", stdout);
	fputs("  (1) 500 gold coins\n", stdout);
	fputs("  (2) Wonderfully ornate dishware\n", stdout);
	funlockfile(stdout);

	return 0;
}
