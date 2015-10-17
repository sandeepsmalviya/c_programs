#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};


struct SLL {
	struct node *head;
};

struct SLL* createSLL() {

	struct SLL *temp =  (struct SLL*)malloc(sizeof(struct SLL));
        temp->head = NULL;
};


struct node *createNode();



void append(struct SLL *sll, int data);
void display(struct SLL *sll);
int countNode(struct SLL *sll);

void insert(struct SLL *sll, int data, int position);

void delfirst(struct SLL *sll);
void dellast(struct SLL *sll);

void delpos(struct SLL *sll, int position);

int main() {

	struct SLL *sll=createSLL();
	int count=0;
	
	display(sll);
	count=countNode(sll);
	printf("Count=%d\n", count);

	append(sll, 10);
	append(sll, 5);
	append(sll, 60);
	append(sll, 70);

	display(sll);
	count=countNode(sll);
	printf("Count=%d\n", count);

	append(sll,20);

	display(sll);
	count=countNode(sll);
	printf("Count=%d\n", count);

	insert(sll, 4, 0);
	display(sll);

	
	insert(sll, 35, 4);
	display(sll);

	
	insert(sll, 15, 2);
	display(sll);

	delfirst(sll);
	display(sll);


	dellast(sll);
	display(sll);
	
	delpos(sll,2);
	display(sll);

	return 0;
}

struct node *createNode() {
	struct node *newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	return newNode;
}

void append(struct SLL *sll, int data) {
	struct node *newNode=createNode();
	newNode->data= data;
	newNode->next=NULL;

	if(sll->head == NULL) {
		sll->head=newNode;
	}
	else {	
		
		struct node *link=sll->head;
		while(link->next != NULL) {
			
			link=link->next;
		}
		link->next=newNode;
	}
}


void display(struct SLL* sll) {
	
	struct node *link = sll->head;
	
	while(link != NULL) {
		
		printf("%2d -> ",link->data);
		link = link->next;
	}
	
	printf("NULL\n");
}


int countNode(struct SLL* sll) {
	
	struct node *link = sll->head;
	int count =0;

	while(link != NULL) {
		count =  count + 1;	
		link = link->next;
	}
	
	return count;
}




void insert(struct SLL *sll, int data, int position) {

	struct node *newNode = createNode();
	struct node *link = sll->head;
	int count = 0;

	newNode->data = data;
	newNode->next = NULL;


	if(position == 0) {

		newNode->next = sll->head;
		sll->head = newNode;
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

void delfirst(struct SLL *sll) {

	struct node *temp = NULL;
	if(sll->head == NULL) {
		printf("Link list is empty..can't delete a node\n");
		return;
	}

	temp = sll->head;
	sll->head = (sll->head)->next;
	
	free(temp);		
}


void dellast(struct SLL *sll) {
	
	struct node *temp = NULL;
	struct node *prev = NULL;

	temp = sll->head;

	if(sll->head == NULL) {

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



void delpos(struct SLL *sll, int position) {

	int index = 0;
	struct node *temp = NULL;
	struct node *prev= NULL;

	int count = countNode(sll);
	if(position == 0) {
		delfirst(sll);
		return;
	}

	if(position == (count-1)) {
		dellast(sll);
		return;
	}

	temp = sll->head;
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

















