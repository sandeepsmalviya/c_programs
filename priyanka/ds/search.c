#include<stdio.h>
#define SIZE 8
int linearSearch(int arr[], int size, int item) {

	int i = 0;
	for(i=0; i<size; i++) {		
		if(item == arr[i]) {	
			return i;
		}
	}	
	return -1;	
}

int binarySearch(int arr[], int size, int item) {

	int low = 0;
	int high = size -1;
	int mid;
	
	while(low <= high) {
	
		mid = (low+high)/2;		

		if(item == arr[mid]) {
			return mid;
		}else if(item < arr[mid]) {
			high = mid-1;			
		}else {
			low = mid+1;
		}
	}
	
	return -1;
}
int main() {


	int linear_arr[] = {40, 50, 30, 20, 15, 60, 70, 45};	
	int binary_arr[] = {10, 20, 30, 40, 50, 60, 70, 80};


	int item = 55;
	int index = linearSearch(linear_arr, SIZE, item);
//	int index = binarySearch(binary_arr, SIZE, item);


	if(index == -1) {
		printf("Item not found\n");
	}else {
		printf("Item found at Index = %d\n", index);
	}
	
	return 0;
}
