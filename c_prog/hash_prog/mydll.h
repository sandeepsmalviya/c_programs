#ifndef MYDLL_H
#define MYDLL_H

#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *prev;
	int data;
	struct node *next;
};


struct DLL {
	struct node *head;
	struct node *tail;
	int count;
};


struct DLL* createDLL();
void deleteDLL(struct DLL *dll);




void displayDLL(struct DLL *dll);
int countNode(struct DLL *dll);

void addfirst(struct DLL *dll, int data);
void addlast(struct DLL *dll, int data);
void addpos(struct DLL *dll, int data, int position);

void delfirst(struct DLL *dll);
void dellast(struct DLL *dll);
void delpos(struct DLL *dll, int position);
int delitem(struct DLL *dll, int data);
int searchDLL(struct DLL *dll, int data);


#endif

