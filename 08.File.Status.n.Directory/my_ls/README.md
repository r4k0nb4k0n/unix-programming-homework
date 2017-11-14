# 실습 과제
```
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        DIR* dp;
        struct dirent* dentry;

        if(argc!=2){
                printf("usage: my_ls dirname\n");
                exit(1);
        }
        if(!(dp=opendir(argv[1]))){
                printf("opendir error.\n");
                exit(2);
        }
        while(1){
                dentry = readdir(dp);
                if(!dentry) break;
                printf("%s\n", dentry->d_name);
        }

        return 0;
}
```
* 위의 ls 프로그램을 수정해서 기능을 추가하라.
	1. .과 ..은 출력되지 않도록 할 것
	2. ls -l을 했을 때의 결과를 참조하여 파일 이름 앞에 아래의 내용이 순서대로 나오도록 할 것
		* 디렉토리(d)/파일(-)/심볼릭링크(l) 파일 표시
		* 접근 권한 (rwxrwxrwx)
		* 파일의 크기
* 수업 시간 종료 안까지(~2017/11/16 13:00) 검사 받지 못하면 소스코드를 프린트하고 어떻게 구현했는지를 알 수 있는 레포트 형식으로 제출할 것
	* 수업 시간 안에 구현하면 5점
	* 레포트 제출 시 4점 만점
