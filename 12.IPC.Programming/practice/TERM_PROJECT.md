# 텀프로젝트 (마감일 : 12월 27일)

## 목표
게시판에서 다운로드 받은 `mini_sh.c`를 아래와 같이 확장하라. (제출일: 12월 27일)
* `>`, `<`와 같은 Redirection 기능을 추가하라.
* `|`와 같은 파이프 기능을 추가하라.

## 리디렉션 `>` 처리
* 예)` # ls > abc.txt`
* 쉘은 `fork`로 `child` 프로세스를 생성한다.
* `child`가 `fork()` 이후 `abc.txt` 파일을 읽기/쓰기 모드로 open한다. 그리고 이 파일의 파일 디스크립터를 `1(STDOUT_FILENO)`번 파일 디스크립터로 복사한다.
* 그 후 `child`는 `ls`로 `exec`한다.
* 아래 프로그램에서 `cmd[1]`은 `ls` 문자열을 가리킨다. `cmd[2]`는 `>`를, 그리고 `cmd[3]`는 `abc.txt`를 가리킨다.

```c
int pid1;
int fd;

pid1 = fork();
if (pid1 == 0) {  /* child */
   fd = open (cmd[3], O_RDWR | O_CREAT | S_IROTH, 0644);
   if (fd < 0) {
        perror ("error");
        exit(-1);
   }
   dup2(fd, STDOUT_FILENO);
   close(fd);
   exec(cmd[1], ...);
   exit(0);
}

/* Parent: Shell */
wait();
```

## 리디렉션 `<` 처리
* 예)` # ls < abc.txt`
* 쉘은 `fork`로 `child` 프로세스를 생성한다.
* `child`가 `fork()` 이후 `abc.txt` 파일을 읽기 모드로 open한다. 그리고 이 파일의 파일 디스크립터를 `0(STDIN_FILENO)`번 파일 디스크립터로 복사한다.
* 그 후 `child`는 `ls`로 `exec`한다.
* 아래 프로그램에서 `cmd[1]`은 `ls` 문자열을 가리킨다. `cmd[2]`는 `<`를, 그리고 `cmd[3]`는 `abc.tx`를 가리킨다.

```c
int pid1;
int fd;

pid1 = fork();
if (pid1 == 0) {  /* child */
   fd = open (cmd[3], O_RDONLY);
   if (fd < 0) {
        perror ("error");
        exit(-1);
   }
   dup2(fd, STDIN_FILENO);
   close(fd);
   exec(cmd[1], ...);
   exit(0);
}

/* Parent: Shell */
wait();
```

## 파이프 `|` 처리
* 예)` # ls | more`
* 쉘은 파이프 `fd`를 생성한다.

* 쉘은 `fork`로 `child1` 프로세스를 생성한다. `child1`은 이후 `ls`로 `exec`할 예정이다.
* `child1`은 `fd[1]`을 `STDOUT_FILENO`로 복사한다.
* `child1`은 `fd[0]`와 `fd[1]`을 닫는다.
* `child1`은 `ls`로 `exec`한다.

* 쉘은 `fork`로 `child2` 프로세스를 생성한다. `child2`는 이후 `more`로 `exec`할 예정이다.
* `child2`은 `fd[0]`을 `STDIN_FILENO`로 복사한다.
* `child2`은 `fd[0]`와 `fd[1]`을 닫는다.
* `child2`은 `more`로 `exec`한다.

* 아래 프로그램에서 `cmd[1]`은 `ls` 문자열을 가리킨다. `cmd[2]`는 `|`를, 그리고 `cmd[3]`는 `more`를 가리킨다.

```c
int  fd[2];
int  pid1, pid2;

pipe(p);

pid1 = fork()

if (pid1 == 0) {  /* First child */
   dup2(fd[1], STDOUT_FILENO);
   close (fd[0]);
   close (fd[1]);
   exec(cmd[1], ...);
}

/* Parent: Shell */

pid2 = fork();
if (pid2 == 0) {  /* Second child */
   dup2(fd[0], STDIN_FILENO);
   close (fd[0]);
   close (fd[1]);
   exec(cmd3, ...);
}

close (fd[0]);
close (fd[1]);

/* Parent : Shell */
wait();
}
```
