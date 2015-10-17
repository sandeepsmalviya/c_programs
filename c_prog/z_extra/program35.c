#include<stdio.h>
int main() {

	char *name[6];//wrong declaration for array of pointers to strings
	int i;

	for(i=0;i<=5;i++) {	
		printf("\nEnter name:");
		scanf("%s", name[i]);
	}
	return 0;
}
