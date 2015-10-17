#include<stdio.h>

int fileWord(char *filePath);
int main() {

	char ch;
	int word=0;
	char filePath[255];
	//char *filePath = "/home/sandeep/c_prog/hello.txt";
	
	printf("Please Enter The Path\n");
	scanf("%s",filePath);

	word = fileWord(filePath);

	printf("word = %d\n", word);
	return 0;
}
int fileWord(char *filePath) {
	
	char ch;
	int word=0;
	FILE *fp = NULL;

	fp = fopen(filePath,"r");
	if(fp==NULL) {		
		printf("Can't open file... exiting\n");
		return -1;
	} else {

		while( (ch=fgetc(fp)) != EOF) {		
			if(ch== '\t' || ch==' ' || ch=='\n') {			
				word = word+1;
			}
	
		}
		fclose(fp);
	}
	return word;
}
