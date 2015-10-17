#include<stdio.h>
#define SIZE 8
int linearsearch (int arr[], int size, int item){
	int i=0;
	for(i=0;i<size;i++) {
		if(item==arr[i]) {
		return i;
		}
	}
	return -1;
}
	
int main() {
	int linear_arr[]={40,50,30,20,15,60,70,45};
	
	int item = 60;	
	int index = linearsearch (linear_arr, SIZE, item);

	if(index == -1){
		printf("Item not found\n");
	} else {
		printf("Item found at index=%d\n", index);
	}
	
	return 0;
}
