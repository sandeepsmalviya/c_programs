#include<stdio.h>

void fileRCWF(char *fileRPath, char *fileWPath);
int main() {

//	char ch;
//	char *fileWPath = "/home/sandeep/c_prog/hellowrite.txt";
 	char fileRPath[255];
	char fileWPath[255];

	printf("Please enter the source path\n");
	scanf("%s",fileRPath);
	printf("Please enter the destination path\n");
	scanf("%s",fileWPath);

	fileRCWF(fileRPath, fileWPath);

	return 0;
}
void fileRCWF(char *fileRPath, char *fileWPath) {
	
	char ch;

	FILE *fpW = NULL;

	fpW = fopen(fileWPath,"w");
	if(fpW==NULL) {		
		printf("Can't open file... exiting\n");
		return;
	}

	while( (ch=fgetc(stdin)) != EOF) {		
		putc(ch, fpW);
	}
	//Ctrl+D to end use input
		
	fclose(fpW);
}
