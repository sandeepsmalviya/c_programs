#include<stdio.h>
int main() {
	
	int i=3;
	printf("\naddress of i=%p",&i);
	printf("\nvalue of i=%d",i);
	printf("\nvalue of i=%d\n",*(&i));
	
	return 0;	
}
