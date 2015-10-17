#include<stdio.h>

int fileLength(char *filePath);
int main() {

	int length=0;
	char filePath[255];

	//char *filePath = "/home/sandeep/c_prog/hello.txt";
	
	printf("Please Enter The Path\n");
	scanf("%s",filePath);
	
	length = fileLength(filePath);

	printf("length = %d\n",length);
	return 0;
}

int fileLength(char *filePath) {

	char ch;
	int length=0;	
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	} else {

	while( (ch=fgetc(fp)) != EOF) {		
		length = length+1;
	}	
	
	fclose(fp);
	}
	return length;
}

