/* 2017-2 Unix Programming
 * fread, fwrite
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *in, *out;
	struct pirate{
		char name[100];
		unsigned long booty;
		unsigned int beard_len;
	} p, blackbeard = {"Edward Teach", 950, 48};

	out = fopen("data", "w");
	if(!out) return 1; /* perror("fopen") */
	if(!fwrite(&blackbeard, sizeof(struct pirate), 1, out)){
		perror("fwrite"); return 1;
	}
	if(fclose(out)) return 1; /* perror("fclose") */

	in = fopen("data", "r");
	if(!in) return 1; /* perror("fopen"); */
	if(!fread(&p, sizeof(struct pirate), 1, in)){
		perror("fread"); return 1;
	}

