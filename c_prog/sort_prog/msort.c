#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[], int size);
void mergeDivide(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);


void mergeSort(int arr[], int size) {
	mergeDivide(arr, 0, size-1);
}
void mergeDivide(int arr[], int l, int r) {
	
	if(l<r) {
		int m=l+(r-l)/2;
		mergeDivide(arr,l,m);
		mergeDivide(arr, m+1, r);
		merge(arr,l,m,r);
	}
}

void merge(int arr[], int l, int m, int r){

	int i,j,k=0;
	int n1=m-l+1;
	int n2=r-m;
	
	int L[n1], R[n2];
	
	for(i=0; i<n1; i++) {
		L[i]=arr[l+i];
	}
	for(j=0; j<n2; j++) {
		R[j]=arr[m+1+j];
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2) {
		if(L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		}else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1) {		
			arr[k] = L[i];
			k++;
			i++;
	}

	while(j<n2) {		
			arr[k] = R[j];
			k++;
			j++;
	}
	
}


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
	mergeSort(arr, size);
	
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

