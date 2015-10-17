#include<stdio.h>
#define SIZE 5
void selectionsort(int arr[], int size) {
	int i,j,temp;
	
	for(i=0; i<size-1; i++) {
		for (j=i+1; j<size; j++) {
			if(arr[i] > arr[j]) {
			
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main() {
	int arr[]={30,20,10,3,5};
	
	int i,size=SIZE;
	printf("Array Before sorting\n");
	for(i=0; i<size; i++) {
		
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	selectionsort(arr, SIZE);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {
			
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
