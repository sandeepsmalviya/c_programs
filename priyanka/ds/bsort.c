#include<stdio.h>
#define SIZE 5
void bubblesort(int arr[], int size) {

	int i, j, temp;
	for(i=0; i<size-1; i++) {
		for(j=0; j<(size-1-i); j++)  {
			if(arr[j]>arr[j+1]) {
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			
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
	bubblesort(arr, SIZE);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {
			
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
