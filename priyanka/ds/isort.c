#include<stdio.h>
#define SIZE 5

void insertionSort(int arr[], int size) {
	int i,j,temp;
	for(i=0; i<size-1; i++) {
		for(j=i+1; j>=1; j--) {
			if(arr[j] < arr[j-1]) {	
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			
			 }else {	
				break;

			}
		}
	}
}

int main() {
	int arr[]={100,1,24,35,20};
	
	int i,size=SIZE;
	printf("Array Before sorting\n");
	for(i=0; i<size; i++) {
		
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	insertionSort(arr, SIZE);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {
			
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
