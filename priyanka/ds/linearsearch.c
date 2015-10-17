#include<stdio.h>
#define SIZE 4
int linearsearch( int arr[], int size , int item);
int main () {
	int i;


	int linear_arr[SIZE];

	for(i=0; i<SIZE; i++) {
		printf("Plz enter integer\n");
		scanf("%d",&linear_arr[i]);
	}

	//printf("enter the list of integer nos.\n");
	//scanf("%d", &arr[i]);
	//int linear_arr[]= {40,45,35,30,20,15,60,70};

		
	int item;


	printf("Plz enter item to find\n");
	scanf("%d",&item);


	int index= linearsearch (linear_arr, SIZE, item);
	if (index==-1) {
		printf("Item not found\n");	
	} else {
		printf("Item found at index=%d\n", index);
	}
 	return 0;
}
int linearsearch(int arr[], int size , int item) {
	int i;
	for ( i=0; i<size; i++) {
		if (item==arr[i]){
		return i;
		}
	}
	return -1;
}
