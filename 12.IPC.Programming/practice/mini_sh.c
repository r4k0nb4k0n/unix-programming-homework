#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FALSE 0
#define TRUE 1

#define EOL	1
#define ARG	2
#define AMPERSAND 3
#define LESSTHAN 4
#define MORETHAN 5
#define PIPE 6

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
		case '<': type = LESSTHAN; break;
		case '>': type = MORETHAN; break;
		case '|': type = PIPE; break;
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
	char *arg[1024];
	int	 type, how;
	int	 quit = FALSE;
	int	 narg = 0;
	int	 finished = FALSE;

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
					int	 i, fid;
					int	 readcount;
					char buf[512];
					fid = open(arg[1], O_RDONLY);
					if (fid >= 0) {
						readcount = read(fid, buf, 512);
						while (readcount > 0) {
							for (i = 0; i < readcount; i++)
								putchar(buf[i]);
							readcount = read(fid, buf, 512);
						}
					}
					close(fid);
				}
			}
			else {
				how = (type == AMPERSAND) ? BACKGROUND : FOREGROUND;
				arg[narg] = NULL;
				if (narg != 0)
					execute(arg, how);
			}
			narg = 0;
			if (type == EOL)
				finished = TRUE;
			break; 
		case LESSTHAN:
			if(narg > 1){
				int pid1;
				int fd;

				pid1 = fork();
				if (pid1 == 0) { /* child */
					fd = open(arg[2], O_RDWR | O_CREAT | S_IROTH, 0644);
					if(fd < 0){
						perror("error");
						exit(-1);
					}
					dup2(fd, STDOUT_FILENO);
					close(fd);
					exec(arg[0], ...);
					exit(0);
				}

				/* Parent: Shell */
				wait();
			}
			break;	
		case MORETHAN:
			if(narg > 1){
				int pid1;
				int fd;
	
				pid1 = fork();
				if(pid1 == 0) { /* child */
					fd = open(arg[2], O_RDONLY);
					if(fd < 0) {
						perror("error");
						exit(-1);
					}
					dup2(fd, STDIN_FILENO);
					close(fd);
					exec(arg[0], ...);
					exit(0);
				}
	
				/* Parent: Shell */
				wait();
			}
			break;
		case PIPE: 
			if(narg > 1){
				int fd[2];
				int pid1, pid2;

				pipe(p);
	
				pid1 = fork();
				if (pid1 == 0) { /* First child */
					dup2(fd[1], STDOUT_FILENO);
					close(fd[0]);
					close(fd[1]);
					exec(arg[0], ...);
				}
	
				/* Parent: Shell */
				
				pid2 = fork();
				if (pid == 0) { /* Second child */
					dup2(fd[0], STDIN_FILENO);
					close(fd[0]);
					close(fd[1]);
					exec(arg[2], ...);
				}
	
				close(fd[0]);
				close(fd[1]);
				
				/* Parent: Shell */
				wait();
			}
			break;
		}
	}
	return quit;
}



main()
{
    char *arg[1024];
	int	 quit;

	printf("msh # ");
	while (gets(input)) {
		quit = parse_and_execute(input);
		if (quit) break;
		printf("msh # ");
	}
}


