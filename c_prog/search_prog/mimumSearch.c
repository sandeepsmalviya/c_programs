#include<stdio.h>
#define SIZE 8
int minimumSearch(int arr[], int size);
int main () {
	int i;
	int item;

	int arr[] = {40,45,35,30,20,15,60,70};
	printf("Array is:\n");
	for(i=0; i<SIZE; i++) {
		printf("%d ", arr[i]);

	}
	printf("\n");
		


	int minimum= minimumSearch (arr, SIZE);		
	printf("Minimum Element =%d\n", minimum);
 	return 0;
}
int minimumSearch(int arr[], int size) {
	int i;
	int min = arr[0];
	
	for ( i=0; i<size; i++) {
		if (arr[i] < min){
			min = arr[i];;
		}
	}
	return min;
}
