#include<stdio.h>
int main() {

	char ch;
	char *fileWPath = "/home/sandeep/c_prog/hellowrite.txt";
	FILE *fpW = NULL;

	fpW = fopen(fileWPath,"w");
	if(fpW==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	}

	while( (ch=fgetc(stdin)) != EOF) {		
		putc(ch, fpW);
	}	
	
	fclose(fpW);
	
	return 0;
}
