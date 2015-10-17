#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

struct Queue {
	struct node *front;
	struct node *rear;
};

struct node* createNode(int data) {

	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}
struct Queue* createQueue() {

	struct Queue* temp = (struct Queue*) malloc(sizeof(struct Queue));
	temp->front = NULL;
	temp->rear = NULL;

	return temp;
}



void dequeue(struct Queue* queue) {

	if(queue->front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	struct node* temp = queue->front;
	queue->front = queue->front->next;

	if(queue->front == NULL) {
		queue->rear = NULL;
	}

	printf("Data %d is deleted from Queue\n", temp->data);
	free(temp);
	
}

void deleteQueue(struct Queue* queue) {

	if(queue->front == NULL) {
		free(queue);
		return;
	}
	
	while(queue->front != NULL) {
		dequeue(queue);
	}

	free(queue);	
}

void enqueue(struct Queue* queue, int data) {

	struct node* temp = createNode(data);
	if(queue->rear == NULL) {
		queue->rear = temp;
		queue->front = temp;
		return;
	}

	queue->rear->next = temp;
	queue->rear = temp;
	
}




void displayQueue(struct Queue* queue) {

		struct node *temp = queue->front;
		while(temp != NULL) {
			printf("%d->", temp->data);
			temp = temp->next;
			
		}
		printf("NULL\n");
}

int main() {
	
	struct Queue* queue = createQueue();
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);

	displayQueue(queue);

	dequeue(queue);
	
	displayQueue(queue);

	

	deleteQueue(queue);


	return 0;
}




