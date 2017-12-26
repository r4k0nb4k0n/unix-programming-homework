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
#define RDIN  4 // '<' Redirection In.
#define RDOUT 5 // '>' Redirection Out.
#define PIPE  6 // '|' Pipe.

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
		case '<': type = RDIN; break;
		case '>': type = RDOUT; break;
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
  int  pid[2], p[2];
  int  fd;
  int  status;

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
  			else if (!strcmp(arg[0], "cd")) chdir(arg[1]); // cd 기능 구현
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
  		case RDIN:
        type = get_token(&arg[++narg]); 
        pid[0] = fork();
        if(pid[0] < 0){ /* Handling fork() error */
          perror("minish: fork error");
          exit(-1);
        }
        else if(pid[0] == 0) { /* child */
          fd = open(arg[2], O_RDONLY);
          if(fd < 0) {
            perror("minish: open error");
            exit(-1);
          }
          dup2(fd, STDIN_FILENO);
          close(fd);
          execlp(arg[0], arg[0], (char*)0);
          perror("minish: command not found"); exit(-1);
        }
        else if(pid[0] > 0) { /* Parent: Shell */
          while(waitpid(pid[0], NULL, 0) < 0)
            if(errno != EINTR) return -1;
        }
        return quit=FALSE;
  		case RDOUT:
        type = get_token(&arg[++narg]); 
        pid[0] = fork();
        if(pid[0] < 0){ /* Handling fork() error */
          perror("minish: fork error");
          exit(-1);
        }
        else if(pid[0] == 0) { /* child */
          fd = open(arg[2], O_RDWR | O_CREAT | S_IROTH, 0644);
          if(fd < 0) {
            perror("minish: open error");
            exit(-1);
          }
          dup2(fd, STDOUT_FILENO);
          close(fd);
          execlp(arg[0], arg[0], (char*)0);
          perror("minish: command not found"); exit(-1);
        }
        else if(pid[0] > 0) { /* Parent: Shell */
          while(waitpid(pid[0], NULL, 0) < 0)
            if(errno != EINTR) return -1;
        }
  		  return quit=FALSE;
      case PIPE:
        type = get_token(&arg[++narg]);
        pipe(p);
        pid[0] = fork();
        if(pid[0] == 0) {
          dup2(p[1], STDOUT_FILENO);
          close(p[0]); close(p[1]);
          execlp(arg[0], arg[0], (char*)0);
          perror("minish: first command not found"); exit(-1);
        }
        /*else if(pid[0] > 0){
          while(waitpid(pid[0], NULL, 0) < 0)
            if(errno != EINTR) return -1;
        }*/
        
        pid[1] = fork();
        if(pid[1] == 0) {
          dup2(p[0], STDIN_FILENO);
          close(p[0]); close(p[1]);
          execlp(arg[2], arg[2], (char*)0);
          perror("minish: second command not found"); exit(-1);
        }
        /*else if(pid[1] > 0){ 
          while(waitpid(pid[1], NULL, 0) < 0)
            if(errno != EINTR) return -1;
        }*/
        close(p[0]); close(p[1]);
        while(waitpid(pid[0], NULL, 0) < 0)
          if(errno != EINTR) return -1;
        while(waitpid(pid[1], NULL, 0) < 0)
          if(errno != EINTR) return -1;
        return quit=FALSE;
    }
  }
	return quit;
}

int main()
{
  char *arg[1024];
	int	 quit;

	printf("msh # ");
	while (gets(input)) {
		quit = parse_and_execute(input);
		if (quit) break;
		printf("msh # ");
	}

  return 0;
}
