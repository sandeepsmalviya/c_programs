#include<stdio.h>
int main() {
	
	char arr[]="sandeepmalviya";
	int l1,l2;
	
	l1=xstrlen(arr);
	l2=xstrlen("priyanka");

	printf("string=%s length=%d\n",arr,l1);
	printf("string=%s length=%d\n","priyanka",l2);
	
	
	return 0;
}
int xstrlen (char *s) {	
	
	int l=0;
	
	while(*s!='\0') {
	
		l++;
		s++;
	}
}
