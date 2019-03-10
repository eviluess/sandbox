#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define FileName "D:\\Downloads\\gittest\\SYS\\GBX.PAC"

int main(int argc, char* argv[])
{
	FILE* file = fopen(FileName, "r+b");
	fseek(file, 0, SEEK_END);
	__int64 size = ftell(file) - 0x60;

	char fillchar = 0x2;

	/*
	46/64 ~ 52/64

	24515/32768

  //0x93c30
  0x93c3a
	*/
	int from = size * 49030/65536;
	int len = size / 65536;

	int to = from + len;
	fseek(file, from + 0x60, SEEK_SET);
	while (from < to)
	{
		fwrite(&fillchar, 1, 1, file);
		from++;
	}

	fclose(file);
	return 0;
}

