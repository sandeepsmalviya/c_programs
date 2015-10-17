#include<stdio.h>

int xstrlen(char *str);
int main(int argc, char *argv[]) {
	char *str=NULL;
	int length=0;
	
	if(argc!=2) {
		printf("Usage:\n<program_name> <string>\n");
		return -1;
	}
	str=argv[1];

	length=xstrlen(str);
	printf("length=%d\n", length);
	
	return 0;
}
int xstrlen(char *str) {

	int l=0;
	char ch;
	char *temp=str;
	while((ch=*temp)!='\0') {
		l++;
		temp++;
	}
	
	return l;
}
