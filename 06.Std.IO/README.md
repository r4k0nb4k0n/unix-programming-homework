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
	* [gets, fgets](./gets_fgets "gets, fgets")
	* [puts, fputs](./puts_fputs "puts, fputs")
* Binary 입출력
	* [fread, fwrite](./fread_fwrite "fread, fwrite")
* 형식화된 입출력
	* scanf(), fscanf(), printf(), fprintf()
### Positioning a Stream
* [ftell, fseek, rewind](./ftell_fseek_rewind "ftell, fseek, rewind")
* [fsetpos_fgetpos](./fsetpos_fgetpos "fsetpos, fgetpos")
### Error Check
* [ferror, feof, clearerr](./ferror_feof_clearerr "ferror, feof, clearerr")
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
### Buffer Flushing
* [fflush](./fflush "fflush")
### 표준 I/O Library Buffering
* Description
	* setbuf
		* fp - 파일 포인터
		* buf - fp가 사용할 버퍼의 포인터
			* buf가 NULL -> 버퍼를 사용하지 않는다는 뜻
			* buf가 !NULL -> 시스템이 할당한 버퍼는 해제되고 프로그램에서 정의한 BUFSIZE(1024)만큼의 char 배열을 버퍼로 사용
	* 이때의 버퍼 사용법은 line buffered
	* setvbuf
		* fp - 파일 포인터
		* buf - fp가 사용할 버퍼의 포인터
			* NULL이 아니면, size 만큼의 사용자 공간 
			* NULL이면 라이브러리 함수에서 적당한 크기 할당
		* mode
			* _IOFBF: Fully buffered
			* _IOLBF: Line buffered
			* _IONBF: Unbuffered
	* size - 사용될 버퍼의 크기
	* 버퍼링의 타입을 결정할 수 있고 buf의 크기를 정의할 수 있어 setbuf()보다 융통성 있음
[setbuf & setvbuf functions](./setbuf_setvbuf "setbuf & setvbuf functions")
