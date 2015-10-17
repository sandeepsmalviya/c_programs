/* A typical recursive implementation of quick sort */
#include<stdio.h>
#include<stdlib.h>
 
 
/* This function takes first element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int l, int r)
{

	int pivot, pivotIndex, down, temp, up;
	pivot = arr[l];

	up = r;
	down = l;
	while(down < up) {
		while(arr[down] <= pivot && down<r) {
			down++;
		}		
		while(arr[up] > pivot) {
			up--;
		}
		if(down < up) {
			temp = arr[down];
			arr[down] = arr[up];
			arr[up] = temp;
		}
	}
	arr[l] = arr[up];
	arr[up] = pivot;

	pivotIndex = up;

	return pivotIndex;

}
 
void quickDivide(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivotIndex = partition(arr, l, r); /* Partitioning index */
        quickDivide(arr, l, pivotIndex - 1);
        quickDivide(arr, pivotIndex + 1, r);
    }
}
 

void quickSort(int arr[], int size) {
	quickDivide(arr, 0, size-1);
}



int main(int argc, char *argv[]) {
	
	int size=0, range=0, npl=0;
	int arg1, arg2, arg3;
	int *arr;
	
	if(argc!=4) {
		printf("Usage:<program_name> <size_array> <size_range> <no_per_line>\n");
		return -1;
	}
	
	arg1=atoi(argv[1]);
	arg2=atoi(argv[2]);
	arg3=atoi(argv[3]);
	
	size=arg1;
	range=arg2;
	npl=arg3;
	
	arr=(int *)malloc (size*sizeof(int));
	int i;
	printf("Array Before sorting\n");
	for(i=0; i<size; i++) {
		
		arr[i]= random()%range;
		printf("%4d ", arr[i]);
	
		if(((i+1)%npl)==0) {
			printf("\n");
		}
	}
	
	printf("\n");
	quickSort(arr, size);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {
			
		printf("%4d ",arr[i]);
		if(((i+1)%npl)==0) {
			printf("\n");
		}
	}
	printf("\n");
	free(arr);
	return 0;
}

