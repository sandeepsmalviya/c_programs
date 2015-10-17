#include<stdio.h>
int main() {

	static char name[]="Burhanpur";
	int i=0;
	while(name[i]!='\0') {
		printf("%c",name[i]);
		i++;
	}
	
	printf("\n");
	return 0;
}
