#include<stdio.h>
int main() {

	char line[255];
	char *filePath = "/home/sandeep/c_prog/hello.txt";
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	}

	while( (fgets(line, 255, fp)) != NULL) {		
		fputs(line, stdout);
	}	
	
	fclose(fp);
	
	return 0;
}
