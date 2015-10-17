#include<stdio.h>
#define SEEK_COUNT 5
void fileseekcount(char * fileRPath, char * fileWPath, int seekCount);

int main() {

	char fileRPath[255];
	char fileWPath[255];

	int seekCount=0;

//	char *fileRPath = "/home/sandeep/c_prog/hello.txt";
//	char *fileWPath = "/home/sandeep/c_prog/hellow.txt";

	printf("Please enter the source path\n");
	scanf("%s",fileRPath);
	printf("Please enter the Destination path\n");
	scanf("%s",fileWPath);

	printf("Please enter the Seekcount\n");
	scanf("%d",&seekCount);

	 fileseekcount(fileRPath, fileWPath, seekCount);
	
	return 0;
}
void fileseekcount(char * fileRPath, char * fileWPath, int seekCount) {
	
	char ch;
	int seekPoint=0;
	
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


		seekPoint++;

		if(seekPoint > seekCount) {
			fputc(ch, fpW);
		}
	}	
	
	fclose(fpR);
	fclose(fpW);

}
