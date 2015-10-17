#include<stdio.h>

void fileImgJpeg(char *fileRPath, char *fileWPath);
int main() {

	char fileRPath[255];
	char fileWPath[255];
	

	//char *fileRPath = "/home/sandeep/c_prog/img.jpeg";
	//char *fileWPath = "/home/sandeep/c_prog/img1.jpeg";
	
	printf("Please Enter The Source Path\n");
	scanf("%s", fileRPath);
	
	printf("Please Enter The Destination Path\n");
	scanf("%s", fileWPath);

	fileImgJpeg(fileRPath, fileWPath);

	return 0;
}

void fileImgJpeg(char *fileRPath, char *fileWPath) {

	int bch;
	unsigned char buffer[1024];

	FILE *fpR = NULL;
	FILE *fpW = NULL;

	fpR = fopen(fileRPath,"rb");
	if(fpR==NULL) {		
		printf("Can't open file for reading... exiting\n");
	//	return ;
	} else {

		fpW = fopen(fileWPath,"wb");
		if(fpW==NULL) {		
			printf("Can't open file for writing... exiting\n");
			//return ;
		} else {

			while( (bch=fread(buffer, 1, 1024 ,fpR)) != 0) {		
				fwrite(buffer, 1, bch  , fpW);
			}	
	
			fclose(fpR);
			fclose(fpW);
		} 
	}

}
