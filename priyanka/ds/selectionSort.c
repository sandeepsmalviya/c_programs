#include<stdio.h>
#include<stdlib.h>

//#define SIZE 5

void selectionSort(int arr[], int size) {
	
	int i, j, temp;
	for(i=0; i< size-1; i++) {		

		for(j=i+1; j<size; j++) {			

			if(arr[i] > arr[j]) {

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main(int argc, char *argv[]) {

	//int arr[SIZE]; //= {10,20, 30, 40, 5};

	int *arr;

	int i;

	int size;
	int itemsPerLine;


	size = atoi(argv[1]);
	itemsPerLine = atoi(argv[2]);

	arr = (int *) malloc(size * sizeof(int));	

	printf("Array before sorting\n");
	for(i=0; i < size; i++) {

		arr[i] = random()%100;
		printf("%2d ", arr[i]);

		if((i+1)% itemsPerLine == 0) {
			printf("\n");
		}
	}
	
	printf("\n");
	selectionSort(arr, size);

	printf("Array after sorting\n");
	for(i=0; i < size; i++) {
		printf("%2d ", arr[i]);
		if((i+1)% itemsPerLine == 0) {
			printf("\n");
		}
	}

	
	printf("\n");

	return 0;
}
