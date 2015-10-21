#include<stdio.h>
#include<stdlib.h>
#define SLL_MAX_SIZE 100
struct node {
	int data;
	struct node *next;
};

struct SLL {
	struct node *head;
	struct node *tail;
	int count;
	int max_size;
};


struct SLL* createSLL(int max_size);
void deleteSLL(struct SLL *sll);

int isSLLEmpty(struct SLL *sll);
int isSLLFull(struct SLL *sll);

struct node *createNode(int data);
void deleteNode(struct node *temp);

void display(struct SLL *sll);
int countNode(struct SLL *sll);

void addfirst(struct SLL *sll, int data);
void addlast(struct SLL *sll, int data);
void addpos(struct SLL *sll, int data, int position);

void delfirst(struct SLL *sll);
void dellast(struct SLL *sll);
void delpos(struct SLL *sll, int position);
void delitem(struct SLL *sll, int data);

int search(struct SLL *sll, int data);


int main() {

	struct SLL *sll=createSLL(-1);
	
	display(sll);

	addfirst(sll, 4);
	display(sll);

	addfirst(sll, 3);
	display(sll);

	addfirst(sll, 2);
	display(sll);

	addfirst(sll, 1);
	display(sll);


	addlast(sll, 5);
	display(sll);

	addpos(sll, 6, 4);

	addlast(sll, 9);
	display(sll);

	delpos(sll, 2);
	display(sll);

	delpos(sll, 2);
	display(sll);

	delpos(sll, 2);
	display(sll);

	deleteSLL(sll);
	sll = NULL;
	return 0;
}


struct SLL* createSLL(int max_size) {
	struct SLL *temp =  (struct SLL*)malloc(sizeof(struct SLL));
        temp->head = NULL;
	temp->tail = NULL;
	temp->count = 0;

	if(max_size < 0) {
		temp->max_size = SLL_MAX_SIZE;
	}else {
		temp->max_size = max_size;
	}
	
	
	return temp;
}

void deleteSLL(struct SLL *sll) {
	while(sll->head != NULL) {	
		delfirst(sll);
	}
	free(sll);
	sll = NULL;
	
}

int isSLLEmpty(struct SLL *sll) {
	if(sll->count == 0) {
		printf("SLL is empty, count = %d and  max_count  = %d\n", sll->count, sll->max_size);		
		return 1;
	}else {
		return 0;
	}
}

int isSLLFull(struct SLL *sll) {
	if(sll->count == sll->max_size) {
		printf("SLL is full max_count reached = %d\n", sll->max_size);		
		return 1;
	}else {
		return 0;
	}
}

struct node *createNode(int data) {
	struct node *newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Memory for SLL is full, can't allocate\n");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void deleteNode(struct node *temp) {
	free(temp);
	temp = NULL;
}

void display(struct SLL* sll) {
	struct node *temp = sll->head;
	while(temp != NULL) {		
		printf("%2d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int countNode(struct SLL* sll) {
	return sll->count;
}

void addfirst(struct SLL *sll, int data) {

	if(isSLLFull(sll)) {
		return;
	}

	struct node *newNode = createNode(data);
	sll->count = sll->count +1;
	if(sll->head == NULL) {
		sll->head=newNode;
		sll->tail= newNode;
	}
	else {
		newNode->next = sll->head;
		sll->head = newNode;
	}
}


void addlast(struct SLL *sll, int data) {

	if(isSLLFull(sll)) {
		return;
	}

	struct node *newNode = createNode(data);
	sll->count = sll->count + 1;
	if(sll->head == NULL) {
		sll->head = newNode;
		sll->tail = newNode;
	}
	else {	
		(sll->tail)->next = newNode;
		sll->tail = newNode;
	}
}


void addpos(struct SLL *sll, int data, int position) {


	if(isSLLFull(sll)) {
		return;
	}

	if(position > sll->count) {
		printf("Position=%d can not be grater than count =%d...\n", position, sll->count);
		return;
	}
	if(position  < 0 ) {
		printf("Position=%d can not be lass than 0\n", position);
		return;
	}
	//if node to be inserted as a first node
	if(position == 0) {
		addfirst(sll, data);
		return;
	}
	//if node to be inserted as a last node
	if(position == sll->count) {
		addlast(sll, data);
		return;
	}

	struct node *newNode = createNode(data);	
	struct node *temp = sll->head;
	struct node *prev = NULL;
	int count = 0;
	while(count < position) {
		prev = temp;	
		temp = temp->next;
		count = count + 1;
	}	
	newNode->next = temp;	
	prev->next = newNode;
	
	sll->count = sll->count + 1;
}

void delfirst(struct SLL *sll) {
	if(sll->head == NULL) {
		printf("Link list is empty..can't delete a node\n");
		return;
	}

	struct node *temp = NULL;
	temp = sll->head;
	sll->head = (sll->head)->next;
	if(sll->head == NULL) {
		sll->tail = NULL;
	}

	sll->count = sll->count - 1;	
	deleteNode(temp);
}


void dellast(struct SLL *sll) {
	if(sll->head == NULL) {
		printf("Link list is empty..can't delete a node\n");
		return;
	}

	struct node *temp = NULL;
	struct node *prev = NULL;
	temp = sll->head;
	while(temp->next != NULL) {
		prev = temp;
		temp = temp->next;		
	}

	sll->tail = prev;
	if(sll->tail == NULL)	 {
		sll->head = NULL;
	}else {
		sll->tail->next = NULL;
	}
	
	sll->count = sll->count - 1;
	deleteNode(temp);
}


void delpos(struct SLL *sll, int position) {
	if(position >= sll->count) {
		printf("Position=%d can not be grater than or equal to count =%d...\n", position, sll->count);
		return;
	}
	if(position  < 0 ) {
		printf("Position=%d can not be lass than 0\n", position);
		return;
	}

	//if node to be deleted as a first node
	if(position == 0) {
		delfirst(sll);
		return;
	}
	//if node to be deleted as a last node
	if(position == sll->count - 1) {
		dellast(sll);
		return;
	}

	struct node *temp = NULL;
	struct node *prev = NULL;
	temp = sll->head;
	int count = 0;
	while(count < position) {
		prev = temp;	
		temp = temp->next;
		count = count + 1;
	}	
	prev->next = temp->next;
		
	sll->count = sll->count - 1;
	deleteNode(temp);
}

void delitem(struct SLL *sll, int data) {
        int pos = search(sll, data);
        if(pos >= 0) {
                delpos(sll, pos);
        }else {
                printf("Item to be deleted = %d not found\n", data);
        }
}


int search(struct SLL *sll, int data) {
	int pos = -1;
	struct node *temp = sll->head;
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

