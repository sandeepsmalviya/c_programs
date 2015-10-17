#include<stdio.h>
#include<stdlib.h>
#include "mydll.h"


static struct node *createNode(int data);
static void deleteNode(struct node *temp);




struct DLL* createDLL() {
	struct DLL *temp =  (struct DLL*)malloc(sizeof(struct DLL));
        temp->head = NULL;
	temp->tail = NULL;
	temp->count = 0;
	
	return temp;
};

void deleteDLL(struct DLL *dll) {
	while(dll->head != NULL) {
		delfirst(dll);
	}

	free(dll);
	dll = NULL;
};

struct node *createNode(int data) {
	struct node *newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void deleteNode(struct node *temp) {
	free(temp);
	temp = NULL;
}

void displayDLL(struct DLL* dll) {
	struct node *link = dll->head;
	printf("NULL ");	
	while(link != NULL) {		
		printf("<- %2d -> ",link->data);
		link = link->next;
	}
	printf(" NULL\n");
}

int countNode(struct DLL* dll) {
	return dll->count;
}

void addfirst(struct DLL *dll, int data) {
	struct node *newNode = createNode(data);
	dll->count = dll->count +1;
	if(dll->head == NULL) {
		dll->head=newNode;
		dll->tail= newNode;
	}
	else {	
		newNode->next = dll->head;
		(dll->head)->prev= newNode;
		dll->head = newNode;
		
	}
}


void addlast(struct DLL *dll, int data) {
	struct node *newNode = createNode(data);
	dll->count = dll->count + 1;
	if(dll->head == NULL) {
		dll->head = newNode;
		dll->tail = newNode;
	}
	else {	
		newNode->prev = dll->tail;
		(dll->tail)->next = newNode;
		dll->tail = newNode;
	}
}


void addpos(struct DLL *dll, int data, int position) {

	if(position > dll->count) {
		printf("Position=%d can not be grater than count =%d...\n", position, dll->count);
		return;
	}

	if(position  < 0 ) {
		printf("Position=%d can not be lass than 0\n", position);
		return;
	}

	//if node to be inserted as a first node
	if(position == 0) {
		addfirst(dll, data);
		return;
	}

	//if node to be inserted as a last node
	if(position == dll->count) {
		addlast(dll, data);
		return;
	}



	struct node *newNode = createNode(data);	
	struct node *temp = dll->head;
	int count = 0;

	while(count < (position-1)) {	
		temp = temp->next;
		count = count + 1;
	}	

	newNode->next = temp->next;	
	(temp->next)->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
	
	dll->count = dll->count + 1;

}

void delfirst(struct DLL *dll) {

	if(dll->head == NULL) {
		printf("Doubly Link list is empty..can't delete a node\n");
		return;
	}

	struct node *temp = NULL;
	temp = dll->head;
	dll->head = (dll->head)->next;

	if(dll->head == NULL) {
		dll->tail = NULL;
	}else {	
		(dll->head)->prev = NULL;
	}

	dll->count = dll->count - 1;		
	deleteNode(temp);
}


void dellast(struct DLL *dll) {
	
	if(dll->head == NULL) {
		printf("Link list is empty..can't delete a node\n");
		return;
	}

	struct node *temp = NULL;
	temp = dll->tail;
	dll->tail = (dll->tail)->prev;
	if(dll->tail == NULL) {
		dll->head = NULL;
	}else {
		(dll->tail)->next = NULL;
	}

	dll->count = dll->count - 1;
	deleteNode(temp);
}


void delpos(struct DLL *dll, int position) {

	if(position >= dll->count) {
		printf("Position=%d can not be grater than or equal to count =%d...\n", position, dll->count);
		return;
	}
	if(position  < 0 ) {
		printf("Position=%d can not be lass than 0\n", position);
		return;
	}

	//if node to be inserted as a first node
	if(position == 0) {
		delfirst(dll);
		return;
	}
	//if node to be inserted as a last node
	if(position == dll->count - 1) {
		dellast(dll);
		return;
	}

	struct node *temp = dll->head;
	int count = 0;
	while(count < position) {	
		temp = temp->next;
		count = count + 1;
	}	
	(temp->prev)->next = temp->next;
	temp->next->prev = temp->prev;
	
	dll->count = dll->count - 1;
	//free(temp);
	deleteNode(temp);
}


int delitem(struct DLL *dll, int data) {
	int pos = searchDLL(dll, data);
	if(pos >= 0) {
		delpos(dll, pos);	
	}
	return pos;
}



int searchDLL(struct DLL *dll, int data) {

	int pos = -1;
	struct node *temp = dll->head;
	int count = 0;
	while(temp != NULL) {
		if(data == temp->data) {
			pos = count;
			break;
		}
		temp = temp->next;	
		count++;
	}
	return pos;	
}



