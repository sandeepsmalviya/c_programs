#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[], int size);

int main(int argc, char *argv[]) {
	
	int size=0, range=0, npl=0;
	int arg1, arg2, arg3;
	int *arr;
//	int arr[]={100,1,24,35,20};
	
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
	bubblesort(arr, size);
	
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
