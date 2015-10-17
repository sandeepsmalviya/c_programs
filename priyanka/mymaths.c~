#include<stdio.h>

void sum(int num1,int num2);
void sub(int num1,int num2);
void mul(int num1,int num2);
void div(int num1,int num2);

int main() {

	int num1, num2;

	int operation;
	int choice;

	do {
		printf("Plz enter the first number\n");
		scanf("%d", &num1);

		printf("Plz enter the second number\n");
		scanf("%d", &num2);

		printf("\tPress 1 for summation\n");
		printf("\tPress 2 for subtraction\n");
		printf("\tPress 3 for multiplication\n");
		printf("\tPress 4 for division\n");
		
		scanf("%d", &operation);

		switch(operation) {
			
			case 1: sum(num1, num2);
				break;

			case 2: sub(num1, num2);
				break;

			case 3: mul(num1, num2);
				break;

			case 4: div(num1, num2);
				break;
		}

	

		printf("\tPress 1 for continue\n");
		printf("\tPress 2 for exit\n");
		scanf("%d", &choice);
		
	}while(choice== 1);

	return 0;
}


void sum(int num1,int num2){
	int result;
	result = num1+num2;
	printf("Summation is = %d\n", result);
}
void sub(int num1,int num2){
	int result;
	result = num1-num2;
	printf("Subtraction is = %d\n", result);
}
void mul(int num1,int num2){

	int result;
	result = num1*num2;
	printf("Multiplication is = %d\n", result);
}
void div(int num1,int num2){
	int result;
	result = num1/num2;
	printf("Division is = %d\n", result);
}
