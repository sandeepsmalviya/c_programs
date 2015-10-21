#include<stdio.h>
#include<stdlib.h>
#define DLL_MAX_SIZE 100
struct node {
	struct node *prev;
	int data;
	struct node *next;
};

struct DLL {
	struct node *head;
	struct node *tail;
	int count;
	int max_size;
};


struct DLL* createDLL();
void deleteDLL(struct DLL *dll);

int isDLLEmpty(struct DLL *dll);
int isDLLFull(struct DLL *dll);

struct node *createNode(int data);
void deleteNode(struct node *temp);


void display(struct DLL *dll);
int countNode(struct DLL *dll);

void addfirst(struct DLL *dll, int data);
void addlast(struct DLL *dll, int data);
void addpos(struct DLL *dll, int data, int position);

void delfirst(struct DLL *dll);
void dellast(struct DLL *dll);
void delpos(struct DLL *dll, int position);
void delitem(struct DLL *dll, int data);
int search(struct DLL *dll, int data);


int main() {

	struct DLL *dll=createDLL(5);

	display(dll);


	addfirst(dll, 4);
	display(dll);

	addfirst(dll, 3);
	display(dll);

	addfirst(dll, 2);
	display(dll);

	addfirst(dll, 1);
	display(dll);


	addlast(dll, 5);
	display(dll);

	addpos(dll, 6, 5);

	addlast(dll, 9);
	display(dll);

	delpos(dll, 2);
	display(dll);

	delpos(dll, 2);
	display(dll);

	delpos(dll, 2);
	display(dll);


	deleteDLL(dll);
	return 0;
}


struct DLL* createDLL(int max_size) {
	struct DLL *temp =  (struct DLL*)malloc(sizeof(struct DLL));
        temp->head = NULL;
	temp->tail = NULL;
	temp->count = 0;

	if(max_size < 0) {
		temp->max_size = DLL_MAX_SIZE;
	}else {
		temp->max_size = max_size;
	}

	
	return temp;
}

void deleteDLL(struct DLL *dll) {
	while(dll->head != NULL) {
		//dellast(dll);
		delfirst(dll);
	}

	free(dll);
	dll = NULL;
}


int isDLLEmpty(struct DLL *dll) {
	if(dll->count == 0) {
		printf("DLL is empty, count = %d and  max_count  = %d\n", dll->count, dll->max_size);		
		return 1;
	}else {
		return 0;
	}
}

int isDLLFull(struct DLL *dll) {
	if(dll->count == dll->max_size) {
		printf("DLL is full max_count reached = %d\n", dll->max_size);		
		return 1;
	}else {
		return 0;
	}
}


struct node *createNode(int data) {
	struct node *newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));

	if(newNode == NULL) {
		printf("Memory for DLL is full, can't allocate\n");
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void deleteNode(struct node *temp) {
	free(temp);
	temp = NULL;
}

void display(struct DLL* dll) {
	struct node *link = dll->head;
	printf("NULL");	
	while(link != NULL) {		
		printf("<- %2d -> ",link->data);
		link = link->next;
	}
	printf("NULL\n");
}

int countNode(struct DLL* dll) {
	return dll->count;
}

void addfirst(struct DLL *dll, int data) {

	if(isDLLFull(dll)) {
		return;
	}

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

	if(isDLLFull(dll)) {
		return;
	}

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

	if(isDLLFull(dll)) {
		return;
	}

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


void delitem(struct DLL *dll, int data) {
	int pos = search(dll, data);
	if(pos >= 0) {
		delpos(dll, pos);
	}else {
		printf("Item to be deleted = %d not found\n", data);
	}
}



int search(struct DLL *dll, int data) {

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

//	if(pos == -1) {
//		printf("Item = %d not found\n", data);
//	} else {
//		printf("Item = %d found at position = %d\n", data, pos);	
//	}

	return pos;	
}



