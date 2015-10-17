#include<stdio.h>
int main() {

	char ch;
	int length=0;

	char *filePath = "/home/sandeep/c_prog/hello.txt";
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	}

	while( (ch=fgetc(fp)) != EOF) {		
		length = length+1;
	}	
	
	fclose(fp);

	printf("length = %d\n",length);
	return 0;
}
