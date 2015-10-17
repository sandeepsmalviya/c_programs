#include<stdio.h>
int main() {

	char ch;
	char *fileRPath = "/home/sandeep/c_prog/hello.txt";
	char *fileWPath = "/home/sandeep/c_prog/helloAppend.txt";

	FILE *fpR = NULL;
	FILE *fpW = NULL;

	fpR = fopen(fileRPath,"r");
	if(fpR==NULL) {		
		printf("Can't open file for reading... exiting\n");
		return -1;
	}

	fpW = fopen(fileWPath,"a");
	if(fpW==NULL) {		
		printf("Can't open file for appending... exiting\n");
		return -1;
	}

	while( (ch=fgetc(fpR)) != EOF) {		
		putc(ch, fpW);
	}	
	
	fclose(fpR);
	fclose(fpW);
	
	return 0;
}
