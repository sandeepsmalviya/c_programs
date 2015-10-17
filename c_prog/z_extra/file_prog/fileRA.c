#include<stdio.h>

void fileappend(char *fileRPath, char * fileWPath);
int main() {

	//char ch;
	char fileRPath[255];
	char fileWPath[255];
	//char *fileRPath = "/home/sandeep/c_prog/hello.txt";
	//char *fileWPath = "/home/sandeep/c_prog/helloAppend.txt";
	
	printf("Please enter the source path\n");
	scanf("%s",fileRPath);
	printf("Please enter the Destination path\n");
	scanf("%s",fileWPath);
	
	fileappend(fileRPath, fileWPath);
	
	return 0;
}
void fileappend(char *fileRPath, char * fileWPath) {
	
	char ch;
	FILE *fpR = NULL;
	FILE *fpW = NULL;

	fpR = fopen(fileRPath,"r");
	if(fpR==NULL) {		
		printf("Can't open file for reading... exiting\n");
		return ;
	}

	fpW = fopen(fileWPath,"a");
	if(fpW==NULL) {		
		printf("Can't open file for appending... exiting\n");
		return ;
	}

	while( (ch=fgetc(fpR)) != EOF) {		
		putc(ch, fpW);
	}	
	
	fclose(fpR);
	fclose(fpW);
}
