#include<stdio.h>
int main() {

	char *names[]={
			"sandeep",
			"piya",
			"rahul",
			"aarti",
			"priyanka",
			"chotu"
		       };
	char *temp;
	
	printf("\nOriginal: %s %s",names[2],names[3]);
	
	temp=names[2];
	names[2]=names[3];
	names[3]=temp;

	printf("\nNew: %s %s",names[2],names[3]);	 
	printf("\n");
	return 0;
}
