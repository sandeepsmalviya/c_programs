#include<stdio.h>

void fileDisplay(char *filePath);

int main() {

	char filePath[255];
//      char *filePath = "/home/sandeep/c_prog/hello.txt";

	printf("Please enter the path\n");
	scanf("%s", filePath);
	
	fileDisplay(filePath);

	return 0;
}

void fileDisplay(char *filePath) {

	char ch;		
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");		
	} else {

		while( (ch=fgetc(fp)) != EOF) {		
			putc(ch, stdout);
		}				

		fclose(fp);
	}	
}
