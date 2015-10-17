#include<stdio.h>

void fileLinebyLine(char *filePath);
int main() {

	char line[255];
	char filePath[255];
	
//	char *filePath = "/home/sandeep/c_prog/hello.txt";
	
	printf("Please Enter The Paath\n");	
	scanf("%s",filePath);
	
	fileLinebyLine(filePath);
	return 0;
}

void fileLinebyLine(char *filePath) {

	char line[255];

	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
	//	return -1;
	} else {

	while( (fgets(line, 255, fp)) != NULL) {		
		fputs(line, stdout);
	}	
	
	fclose(fp) ;
	}
}
