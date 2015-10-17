#include<stdio.h>
#define SIZE 5
int linearsearch(int arr[], int size, int item);

int main() {
	
	int linear_arr[] = {20,30,45,15,3};
	int item=3;
	int index = linearsearch(linear_arr, SIZE, item);

	if(index==-1) {
		printf("Item not found\n");
	} else {
		printf("Item found at index=%d\n",index);
		}
		
	return 0;
}
int linearsearch(int arr[], int size, int item) {
	int i=0;
	for(i=0; i<size; i++) {
		if(item==arr[i]) {
			return i;
		}
	}
	return-1;
}
