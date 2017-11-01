# 06. Standard Input and output
### System Call vs. Standard Library
![system_call](./system_call.png?raw=true "system_call")
### Stream과 FILE 구조체
* Stream(스트림)
	* 프로그램과 파일 사이의 자료흐름
	* 표준 입출력 함수는 스트림을 매개로 파일에 접근
	* System Call function의 경우 file descriptor를 통해 파일에 접근
* FILE 구조체
	* 하나의 스트림을 다루기 위한 정보를 포함하는 구조체
	* 스트림을 개바하면 FILE 구조체에 대한 포인터 얻음(fopen)
	* 표준 입출력 함수는 위에서 얻은 파일 포인터를 인자로 하여 파일을 다룸
	* 프로세스는 커널에 의해 기본적으로 3개의 스트림을 자동으로 얻음
		* 표준 입력: stdin
		* 표준 출력: stdout
		* 표준 에러: stderr
	* FILE Structure (/usr/include/libio.h에 정의)
![FILE_structure](./FILE_structure.png?raw=true "FILE_structure")
### 표준 I/O Buffering
* 목적
	* 파일 접근 횟수와 내부 시스템 접근 횟수를 최소화
* 종류
	* Fully buffered
		* 버퍼가 꽉 찬 경우에만 실질적인 입출력이 일어남
	* Line buffered
		* '\n' 문자에 의해 입출력이 발생
		* 예: 표준입력(stdin), 표준출력(stdout)
	* Unbuffered
		* App과 파일 사이에 버퍼를 사용하지 않음
		* 예: 표준 에러(stderr)
### 파일 입출력 함수들
* [fopen](./fopen "fopen")
* [freopen, fdopen](./freopen_fdopen "freopen, fdopen")
* [fclose](./fclose "fclose")
### 입출력 함수의 종류
* 문자 단위 입출력
	* [getc, fgetc, getchar](./getc_fgetc_getchar "getc, fgetc, getchar")
	* [ungetc](./ungetc "ungetc")
	* [putc, fputc, putchar](./putc_fputc_putchar "putc, fputc, putchar")
* 줄단위 입출력
	* gets(), fgets(), puts(), fputs()
* Binary 입출력
	* fread(), fwrite()
* 형식화된 입출력
	* scanf(), fscanf(), printf(), fprintf()
