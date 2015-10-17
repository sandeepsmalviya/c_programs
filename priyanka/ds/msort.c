#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void merge(int arr[], int s1, int e1, int s2, int e2) {

	int i=s1, j=s2, k=s1;
	int l1 = e1-s1 +1;
	int l2 = e2-s2+1;
	int l = l1+l2;

	printf("Merge called s1=%d e1=%d s2=%d e2=%d\n", s1,e1,s2,e2);	

	int *arrp1 = (int *) malloc(sizeof(int)*l1);	
	int *arrp2 = (int *) malloc(sizeof(int)*l2);


	int a1,a2;
	
	printf("Reched here1\n");
	for(a1=0; a1<=e1; a1++) {
		arrp1[a1] = arr[a1+s1];
	}

	printf("Reched here2\n");
	for(a2=0; a2<=e2; a2++) {
		arrp2[a2] = arr[a2+s2];
	}



	printf("Reched here3\n");
	while(i<=e1 && j<=e2) {
		if(arrp1[i] < arrp2[j]) {
			arr[k] = arrp1[i];
			k++;
			i++;
		}else {
			arr[k] = arrp2[j];
			k++;
			j++;
		}
	}

	while(i<=e1) {		
			arr[k] = arrp1[i];
			k++;
			i++;
	}


	while(j<=e2) {		
			arr[k] = arrp2[j];
			k++;
			j++;
	}


	
	printf("Array after sorting\n");
	for(i=0;i<SIZE; i++) {
			
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}


void divide(int arr[], int start, int end) {

	int m;
	printf("Divide called start = %d\t end=%d\n\n", start,end);	

	if(start<end) {
				
		m = (end+start)/2;
		divide(arr, start, m);
		divide(arr, m+1, end);
		merge(arr, start, m, m+1, end);		
	}

}



void mergesort(int arr[], int size) {


	divide(arr, 0, size-1);
}





int main() {
	int arr[]={75,40,32,80,16,20,50,90,15};
	
	int i,size=SIZE;

	printf("Array Before sorting\n");
	for(i=0; i<size; i++) {
		
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	mergesort(arr, SIZE);
	
	printf("Array after sorting\n");
	for(i=0;i<size; i++) {
			
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
