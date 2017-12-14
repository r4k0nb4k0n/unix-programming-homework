#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void usr1_handler(int signo){
  printf("signal received from child!!\n");
}

int main(){
  int pid;

  if( (pid = fork()) > 0 ){
    signal(SIGUSR1, usr1_handler);
    pause();

    exit(0);
  }
  else if( pid == 0 ){
    int i, sum = 0;
    for(i=1;i<=100;i++) sum+=i;
    printf("sum result from 1 to 100: %d\n", sum);
    // race condition.
    kill(getppid, SIGUSR1);
    exit(0);
  }
  return 0;
}
