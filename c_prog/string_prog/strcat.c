#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* xstrcat(char *str1, char *str2);
int main(int argc, char *argv[]) {
	char *str1=NULL;
	char *str2=NULL;
	char *str3=NULL;

	
	if(argc!=3) {
		printf("Usage:\n<program_name> <string1> <string2>\n");
		return -1;
	}
	str1=argv[1];
	str2=argv[2];

	str3=xstrcat(str1,str2);
	printf("str3=%s\n", str3);
	
	return 0;
}
char* xstrcat(char *str1, char *str2) {
	
	
	char *str3=NULL;
	char *temp=NULL;
	int l1=0;
	int l2=0;
	l1 = strlen(str1);
	l2 = strlen(str2);
	
	str3 = (char*)malloc(l1+l2+1);	
	temp = str3;

	while(*str1!='\0') {
		*temp=*str1;
		temp++;
		str1++;
	}
	while(*str2!='\0') {
		*temp=*str2;
		temp++;
		str2++;
	}
	
	*temp = '\0';
		
	return str3;
}
