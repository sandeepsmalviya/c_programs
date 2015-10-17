#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void xstrcpy(char *str1,char *str2);
int main(int argc, char *argv[]) {
	char *str1=NULL;
	char str2[100];
	
	if(argc!=2) {
		printf("Usage:\n<program_name> <string>\n");
		return -1;
	}
	str1=argv[1];

	xstrcpy(str1,str2);
	printf("str2=%s\n", str2);
	
	return 0;
}
void xstrcpy(char *str1, char *str2) {
		
	while(*str1!='\0') {
		*str2=*str1;
		str2++;
		str1++;
	}
	
	*str2= '\0';
		
}
