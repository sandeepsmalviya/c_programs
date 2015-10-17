#include<stdio.h>
int main() {

	char ch;
	char *filePath = "/home/sandeep/c_prog/hello.txt";
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	}

	while( (ch=fgetc(fp)) != EOF) {		
		putc(ch, stdout);
	}	
	
	fclose(fp);
	
	return 0;
}
