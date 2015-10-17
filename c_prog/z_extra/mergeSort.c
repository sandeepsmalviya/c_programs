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
	
	printf("Left Array ...\n");
	for(i=0; i<n1; i++) {
		L[i]=arr[l+i];
		printf("%d ", L[i]);
	}
	printf("\n");
	printf("Right Array ...\n");
	for(j=0; j<n2; j++) {
		R[j]=arr[m+1+j];
		printf("%d ", R[j]);
	}
	printf("\n");

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


	
	printf("Array after sorting\n");
	for(i=0;i<9; i++) {			
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}


int main() {
	int arr[]={75,40,32,80,16,20,50,90,15};
	
	int i,size=9;

	printf("Array Before sorting\n");
	for(i=0; i<size; i++) {		
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	mergeSort(arr, size);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {			
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
