#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};


struct node *createNode();
void append(struct node **phead, int data);
void display(struct node *head);
int countNode(struct node *head);

void insert(struct node **phead, int data, int position);

void delfirst(struct node **phead);
void dellast(struct node **phead);

void delpos(struct node **phead, int position);

int main() {

	struct node *head=NULL;
	int count=0;
	
	display(head);
	count=countNode(head);
	printf("Count=%d\n", count);

	append(&head, 10);
	append(&head, 5);
	append(&head, 60);
	append(&head, 70);

	display(head);
	count=countNode(head);
	printf("Count=%d\n", count);

	append(&head,20);

	display(head);
	count=countNode(head);
	printf("Count=%d\n", count);

	insert(&head, 4, 0);
	display(head);

	
	insert(&head, 35, 4);
	display(head);

	
	insert(&head, 15, 2);
	display(head);

	delfirst(&head);
	display(head);


	dellast(&head);
	display(head);
	
	delpos(&head,2);
	display(head);
	return 0;
}

struct node *createNode() {
	struct node *newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	return newNode;
}

void append(struct node **phead, int data) {
	struct node *newNode=createNode();
	newNode->data= data;
	newNode->next=NULL;

	if(*phead == NULL) {
		*phead=newNode;
	}
	else {	
		
		struct node *link=*phead;
		while(link->next != NULL) {
			
			link=link->next;
		}
		link->next=newNode;
	}
}


void display(struct node *head) {
	
	struct node *link = head;
	
	while(link != NULL) {
		
		printf("%2d -> ",link->data);
		link = link->next;
	}
	
	printf("NULL\n");
}


int countNode(struct node *head) {
	
	struct node *link = head;
	int count =0;

	while(link != NULL) {
		count =  count + 1;	
		link = link->next;
	}
	
	return count;
}




void insert(struct node **phead, int data, int position) {

	struct node *newNode = createNode();
	struct node *link = *phead;
	int count = 0;

	newNode->data = data;
	newNode->next = NULL;


	if(position == 0) {

		newNode->next = *phead;
		*phead = newNode;
	}

	while(link != NULL) {
		
		link = link->next;	
		count++;

		if(count == (position-1)) {
			
			//Linking code
			newNode->next = link->next;
			link->next = newNode;

			break;
		}
	}
}

/*Deletion code*/

void delfirst(struct node **phead) {

	struct node *temp = NULL;
	if(*phead == NULL) {
		printf("Link list is empty..can't delete a node\n");
		return;
	}

	temp = *phead;
	*phead = (*phead)->next;
	
	free(temp);		
}


void dellast(struct node **phead) {
	
	struct node *temp = NULL;
	struct node *prev = NULL;

	temp = *phead;

	if(*phead == NULL) {

		printf("Link list is empty..can't delete a node\n");
		return;
	}

	while(temp->next != NULL) {
		prev= temp;
		temp = temp->next;
	}
	
	prev->next = NULL;
	free(temp);
}



void delpos(struct node **phead, int position) {

	int index = 0;
	struct node *temp = NULL;
	struct node *prev= NULL;

	int count = countNode(*phead);
	if(position == 0) {
		delfirst(phead);
		return;
	}

	if(position == (count-1)) {
		dellast(phead);
		return;
	}

	temp = *phead;
	prev = NULL;
	index = 0;
	while(index < position) {

		prev = temp;
		temp = temp->next;
		
		index++;
	}

	prev->next = temp->next;
	free(temp);
	
}


















