#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void xstrrev(char *str);
int main(int argc, char *argv[]) {
	char *str1=NULL;
	
	if(argc!=2) {
		printf("Usage:\n<program_name> <string>\n");
		return -1;
	}
	str1=argv[1];

	xstrrev(str1);
	printf("str1=%s\n", str1);
	
	return 0;
}
		
void xstrrev(char *str){

	char *t1=str;
	char *t2=str;
	char ch;
	
	while(*t2 != '\0') {
		t2++;		
	}
	t2--;	

	while(t1 <= t2) {

		ch= *t1;
		*t1=*t2;
		*t2=ch;	
		t1++;
		t2--;
	}
		
}
