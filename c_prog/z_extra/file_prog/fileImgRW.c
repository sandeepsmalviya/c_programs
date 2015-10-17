#include<stdio.h>
int main() {

	int bch;


	unsigned char buffer[1024];

	char *fileRPath = "/home/sandeep/c_prog/img.jpeg";
	char *fileWPath = "/home/sandeep/c_prog/img1.jpeg";

	FILE *fpR = NULL;
	FILE *fpW = NULL;

	fpR = fopen(fileRPath,"rb");
	if(fpR==NULL) {		
		printf("Can't open file for reading... exiting\n");
		return -1;
	}

	fpW = fopen(fileWPath,"wb");
	if(fpW==NULL) {		
		printf("Can't open file for writing... exiting\n");
		return -1;
	}

	while( (bch=fread(buffer, 1, 1024 ,fpR)) != 0) {		
		fwrite(buffer, 1, bch  , fpW);
	}	
	
	fclose(fpR);
	fclose(fpW);
	
	return 0;
}
