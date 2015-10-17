#include<stdio.h>

void fileDisplay(char *filePath);

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("Usage:\n");
		printf("<prog_name>  <file_path>");
	}
	char *filePath = argv[1];
	
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
