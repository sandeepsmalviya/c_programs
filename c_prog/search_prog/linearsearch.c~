#include<stdio.h>
#define SIZE 8
int linearsearch( int arr[], int size , int item);
int main () {
	int i;
	int item;

	int linear_arr[] = {40,45,35,30,20,15,60,70};
	printf("Array is:\n");
	for(i=0; i<SIZE; i++) {
		printf("%d ", linear_arr[i]);

	}
	printf("\n");
		

	printf("Plz enter item to find\n");
	scanf("%d",&item);

	int index= linearSearch (linear_arr, SIZE, item);
	if (index==-1) {
		printf("Item not found\n");	
	} else {
		printf("Item found at index=%d\n", index);
	}
 	return 0;
}
int linearSearch(int arr[], int size , int item) {
	int i;
	for ( i=0; i<size; i++) {
		if (item==arr[i]){
		return i;
		}
	}
	return -1;
}
