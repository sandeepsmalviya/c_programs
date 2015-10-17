#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct Stack {
	struct node *top;
};

struct Stack* createStack() {

	struct Stack *temp =  (struct Stack*)malloc(sizeof(struct Stack));
	temp->top = NULL;
}




struct node* createNode(int data);

void push(struct Stack *stack, int data);
int pop(struct Stack *stack);

void displayStack(struct Stack *stack);


int main() {
	
	struct Stack *stack = createStack();
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	displayStack(stack);

	pop(stack);
	pop(stack);

	pop(stack);
	pop(stack);

	pop(stack);
	pop(stack);

	displayStack(stack);

	push(stack, 40);
	push(stack, 50);
	
	displayStack(stack);
	return 0;
}


struct node* createNode(int data) {

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}



void push(struct Stack *stack, int data) {
	
	struct node *temp = createNode(data);
	temp->next = stack->top;
	stack->top = temp;
	
	printf("Item %d is pushed\n", data);
}


int pop(struct Stack *stack) {

	struct node *temp = stack->top;
	int data;
	if(stack->top == NULL) {
		printf("Stack is empty\n");
		return;
	}

	stack->top = (stack->top)->next;
	data = temp->data;

	printf("Item %d is popped\n", data);
	free(temp);
	return data;
}
void displayStack(struct Stack *stack) {

		
	printf("\n");
	while(stack->top != NULL) {
		printf("%2d -> ", stack->top->data);
		stack->top = stack->top->next;
	}
	printf("NULL\n\n");
}










