#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};


struct node* createNode(int data);

void push(struct node **ptop, int data);
int pop(struct node **ptop);

void displayStack(struct node *top);


int main() {
	
	struct node *top = NULL;
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	displayStack(top);

	pop(&top);
	pop(&top);

	pop(&top);
	pop(&top);

	pop(&top);
	pop(&top);

	displayStack(top);

	push(&top, 40);
	push(&top, 50);
	
	displayStack(top);
	return 0;
}


struct node* createNode(int data) {

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}



void push(struct node **ptop, int data) {
	
	struct node *temp = createNode(data);
	temp->next = *ptop;
	*ptop = temp;
	
	printf("Item %d is pushed\n", data);
}


int pop(struct node **ptop) {

	struct node *temp = *ptop;
	int data;
	if(*ptop == NULL) {
		printf("Stack is empty\n");
		return;
	}

	*ptop = (*ptop)->next;
	data = temp->data;

	printf("Item %d is popped\n", data);
	free(temp);
	return data;
}
void displayStack(struct node *top) {

		
	printf("\n");
	while(top != NULL) {
		printf("%2d -> ", top->data);
		top = top->next;
	}
	printf("NULL\n\n");
}










