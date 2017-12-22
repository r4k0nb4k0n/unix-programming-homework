/* 2017-2 Unix Programming
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 * 10장 프로세스 
 * 실습 2
 * 과제 1. 프로그램에 인자로 들어오는 파일을 open하여 line, word, character의 수를 계산하고
 * 출력하는 프로그램인 my_wc를 작성하라.
 * 과제 2. 다수의 텍스트 파일의 이름을 인자로 받고 각각의 파일에 대하여 별도의 프로세스가 
 * 과제 1에서 작성한 my_wc를 exec하여 실행되도록 하는 m_my_wc 프로그램을 작성하라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, int *argv[]){
	if( argc == 1 ){
		printf("usage : my_wc textfile");
		exit(1);
	}
	int line, word, character;
	line = word = character = 0;
	int fp = fopen(argv[1], "r");
	while ( fp != EOF ){
		char c = fgetc(fp);
		if(c == ' '){
			word++;
		}
		else if(c == '\n'){
			line++;
		}
		else{
			character++;
		}
	}
	if(word != 0) word++;
	printf("line: %d\n", line);
	printf("word: %d\n", word);
	printf("character: %d\n", character);
	return 0;
}
