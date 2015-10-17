#include<stdio.h>

void filecopy(char *fileRPath, char *fileWPath);	
int main() {

	//	char ch;
	char fileRPath[255];
	char fileWPath[255];
	//char *fileRPath = "/home/sandeep/c_prog/hello.txt";
	//char *fileWPath = "/home/sandeep/c_prog/hellow.txt";

	printf("Please Enter The Source Path\n");
	scanf("%s", fileRPath);
	printf("Please Enter The Destination Path\n");
	scanf("%s", fileWPath);

	filecopy(fileRPath,fileWPath);
	
	return 0;
}

void filecopy(char *fileRPath, char *fileWPath) {
	char ch;

	FILE *fpR = NULL;
	FILE *fpW = NULL;

	fpR = fopen(fileRPath,"r");
	if(fpR==NULL) {		
		printf("Can't open file for reading... exiting\n");
		return;
	}

	fpW = fopen(fileWPath,"w");
	if(fpW==NULL) {		
		printf("Can't open file for writing... exiting\n");
		return;
	}

	while( (ch=fgetc(fpR)) != EOF) {		
		putc(ch, fpW);
	}	
	
	fclose(fpR);
	fclose(fpW);
}
