#include<stdio.h>

int xstrcmp(char *str1, char *str2);
int main(int argc, char *argv[]) {
	char *str1=NULL;
	char *str2=NULL;
	int cmp=0;
	
	if(argc!=3) {
		printf("Usage:\n<program_name> <string1> <string2>\n");
		return -1;
	}
	str1=argv[1];
	str2=argv[2];

	cmp=xstrcmp(str1,str2);
	printf("cmp=%d\n", cmp);
	
	return 0;
}
int xstrcmp(char *str1, char *str2) {

	int cmp=0;
	while(*str1 == *str2) {	

		if(*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	cmp = *str1 - *str2;

	return cmp;
}
