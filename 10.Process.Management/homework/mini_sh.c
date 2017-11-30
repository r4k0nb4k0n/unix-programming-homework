#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define FALSE 0
#define TRUE 1

#define EOL	1
#define ARG	2
#define AMPERSAND 3

#define FOREGROUND 0
#define BACKGROUND 1

static char	input[512];
static char	tokens[1024];
char		*ptr, *tok;

int get_token(char **outptr)
{
	int	type;

	*outptr = tok;
	while ((*ptr == ' ') || (*ptr == '\t')) ptr++;

	*tok++ = *ptr;

	switch (*ptr++) {
		case '\0' : type = EOL; break;
		case '&': type = AMPERSAND; break;
		default : type = ARG;
			while ((*ptr != ' ') && (*ptr != '&') &&
				(*ptr != '\t') && (*ptr != '\0'))
				*tok++ = *ptr++;
	}
	*tok++ = '\0';
	return(type);
}

int execute(char **comm, int how)
{
	int	pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "minish : fork error\n");
		return(-1);
	}
	else if (pid == 0) {
		execvp(*comm, comm);
		fprintf(stderr, "minish : command not found\n");
		exit(127);
	}
	/* How to change STDOUT to the specific file?
	 * open(), and dup2()
	 */
	if (how == BACKGROUND) {	/* Background execution */
		printf("[%d]\n", pid);
		return 0;
	}		
	/* Foreground execution */
	while (waitpid(pid, NULL, 0) < 0)
		if (errno != EINTR) return -1;
	return 0;
}

int parse_and_execute(char *input)
{
	char	*arg[1024];
	int	type, how;
	int	quit = FALSE;
	int	narg = 0;
	int	finished = FALSE;

	ptr = input;
	tok = tokens;
	while (!finished) {
		switch (type = get_token(&arg[narg])) {
		case ARG :
			narg++;
			break;
		case EOL :
		case AMPERSAND:
			if (!strcmp(arg[0], "quit")) quit = TRUE;
			else if (!strcmp(arg[0], "exit")) quit = TRUE;
			else if (!strcmp(arg[0], "cd")) {
				/* Do something */
			}
			else if (!strcmp(arg[0], "type")) {
				if (narg > 1) {
					int	i, fid;
					int	readcount;
					char	buf[512];
					/*  학생들이 프로그램 작성할 것
					fid = open(arg[1], ...);
					if (fid >= 0) {
						readcount = read(fid, buf, 512);
						while (readcount > 0) {
							for (i = 0; i < readcount; i++)
								putchar(buf[i]);
							readcount = read(fid, buf, 512);
						}
					}
					close(fid);
					*/
				}
			}
			else { // 외부 프로그램. fork, exec.
				how = (type == AMPERSAND) ? BACKGROUND : FOREGROUND;
				arg[narg] = NULL;
				if (narg != 0)
					execute(arg, how);
			}
			narg = 0;
			if (type == EOL)
				finished = TRUE;
			break; 
		}
	}
	return quit;
}



main()
{
   	char 	*arg[1024];
	int		quit;

	printf("msh # ");
	while (gets(input)) {
		quit = parse_and_execute(input);
		if (quit) break;
		printf("msh # ");
	}
}


