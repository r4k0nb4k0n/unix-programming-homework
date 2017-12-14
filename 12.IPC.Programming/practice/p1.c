#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int catchint(int signo){
  printf("SIGINT Received\n");
  signal(SIGINT, SIG_DFL);
}

int main(){
  signal(SIGINT, catchint);
  
  int i;
  for(i=1;i<=100;i++){
    printf("sleep... %d\n", i);
    sleep(1);
  }
  return 0;
}
