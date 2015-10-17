#include<stdio.h>
#include<stdlib.h>

struct node  {

	int data;
	struct node* next;
};

struct Queue {

	struct node* front;
	struct node* rear;
};


struct Queue* createQueue() {

	struct Queue* temp = (struct Queue*) malloc(sizeof(struct Queue));
	temp->front = NULL;
	temp->rear = NULL;
	
	printf("Queue is successfully created\n\n");
	return temp;
}

struct node* createNode(int data) {

	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;

}

void enqueue(struct Queue* queue, int data) {

	struct node* temp = createNode(data);

	if(queue->rear == NULL) {
		queue->rear = temp;
		queue->front = temp;				
		
	}else {
		queue->rear->next = temp;
		queue->rear = temp;
		
	}

	queue->rear->next = queue->front;
	
}


void display(struct Queue* queue) {
	
	struct node* temp= queue->front;
	printf("Display:");
	if(temp == NULL) {

		printf("Circular queue is empty\n");
		return;
	}

	do {

				
		printf("%d->",temp->data);		
		temp = temp->next;

	} while(temp != queue->rear->next);
		
	printf("CQueue\n");
}

int delqueue(struct Queue* queue) {

	
	struct node* temp = NULL;
	if(queue->front == NULL) {	

		printf("CQueue is empty..Can't delete\n");
		return 0;
	}
	
	if(queue->front == queue->rear) {	
		temp = queue->front;
		queue->front =NULL;
		queue->rear = NULL;

		printf("Node %d is deleted\n",temp->data);
		free(temp);

		return 1;
	}

	temp = queue->front;
	queue->front = queue->front->next;
	queue->rear->next = queue->front;
	
	printf("Node %d is deleted\n",temp->data);
	free(temp);
	
	return 1;	
}

void freeQueue(struct Queue* queue) {
	
	int i = 0;
	while( (i=delqueue(queue)) != 0) {	
		delqueue(queue);
	}

	printf("CQueue is successfully freed\n");
	free(queue);
}
int main() {

	struct Queue* queue = createQueue();	
	display(queue);

	enqueue(queue, 10);
	display(queue);

	enqueue(queue, 20);
	display(queue);

	enqueue(queue, 30);	
	display(queue);

	delqueue(queue);
	display(queue);

	delqueue(queue);
	display(queue);
	delqueue(queue);
	display(queue);
	delqueue(queue);
	display(queue);

	freeQueue(queue);
	return 0;
}

