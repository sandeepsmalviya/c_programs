#include<stdio.h>
#define SIZE 8
int maximumSearch(int arr[], int size);
int main () {
	int i;
	int item;

	int arr[] = {40,45,35,30,20,15,60,70};
	printf("Array is:\n");
	for(i=0; i<SIZE; i++) {
		printf("%d ", arr[i]);

	}
	printf("\n");
		


	int maximum= maximumSearch (arr, SIZE);		
	printf("Maximum Element =%d\n", maximum);
 	return 0;
}
int maximumSearch(int arr[], int size) {
	int i;
	int max = arr[0];
	
	for ( i=0; i<size; i++) {
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}
