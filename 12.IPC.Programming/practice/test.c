#include <stdio.h>
int main(){
  int i, input;
  for(i=0;i<5;i++){
    scanf("%d", &input);
    printf("%d\n", input*2);
  }
  return 0;
}
