#include<stdio.h>
int main() {

	char ch;
	int word=0;

	char *filePath = "/home/sandeep/c_prog/hello.txt";
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	}

	while( (ch=fgetc(fp)) != EOF) {		
		if(ch== '\t' || ch==' ' || ch=='\n') {			
			word = word+1;
		}
	}	
	
	fclose(fp);

	printf("word = %d\n", word);
	return 0;
}
