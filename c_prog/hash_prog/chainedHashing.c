#include<stdio.h>
#include<stdlib.h>

#include "mydll.h"


#define HASH_SIZE 100

struct HashTable {
	int ht_size;
	int ht_count_element;
	struct DLL **p_dll;
};


int insert(struct HashTable *ht, int data);
int delete(struct HashTable *ht, int data);
int search(struct HashTable *ht, int data);
void printHashTable(struct HashTable *ht);

struct HashTable* createHashTable(int hashSize) {

	struct HashTable* ht = (struct HashTable*) malloc(sizeof(struct HashTable));
	struct DLL **p_dll  = (struct DLL **) malloc(hashSize * sizeof(struct DLL*));	
	ht->ht_size = hashSize;
	ht->p_dll = p_dll;

	int i=0;
	for(i=0; i < hashSize; i++) {
		ht->p_dll[i] = createDLL();
	}
	printf("HashTable created with ht_size = %d ...\n", ht->ht_size);
	return ht;
}

void deleteHashTable(struct HashTable* ht) {

	//printf("=========");
	int i=0;
	for(i=0; i < ht->ht_size; i++) {
		deleteDLL(ht->p_dll[i]);
		ht->p_dll[i] = NULL;
	}

	free(ht->p_dll);
	printf("HashTable deleted with ht_size = %d, count_element=%d ...\n", ht->ht_size, ht->ht_count_element);
	ht->p_dll = NULL;
	free(ht);
	ht = NULL;
}

void printHashTable(struct HashTable *ht) {
	printf("HashTable ht_size = %d, Contents are...\n", ht->ht_size);
	int i=0;
	for(i=0; i < (ht->ht_size); i++) {
		printf("\t[%d] ->", i);
		printf(" DLL: Count =  %d => ", ht->p_dll[i]->count);
		displayDLL(ht->p_dll[i]);
	}
}

int convertToHashCode(int data) {
	return data;
}

int hash(int hashKey, int modSize) {
	return hashKey % modSize;
}

int insert(struct HashTable* ht, int data) {
	int hk = convertToHashCode(data);
	int ht_Index =  hash(hk, ht->ht_size);
	
	addfirst(ht->p_dll[ht_Index], data);

	ht->ht_count_element = ht->ht_count_element + 1;

	return ht_Index;
}

int search(struct HashTable* ht, int data) {
	int hk = convertToHashCode(data);
	int ht_Index =  hash(hk, ht->ht_size);

	int pos = searchDLL(ht->p_dll[ht_Index], data);

	return pos;
}


int delete(struct HashTable* ht, int data) {


	int hk = convertToHashCode(data);
	int ht_Index =  hash(hk, ht->ht_size);	

	int pos = delitem(ht->p_dll[ht_Index], data);

	ht->ht_count_element = ht->ht_count_element -  1;

	return pos;
}

int main() {
	struct HashTable *ht = createHashTable(HASH_SIZE);


	printHashTable(ht);

//	printf("Insert Index list = %d\n", insert(ht, 10));
//	printf("Insert Index list = %d\n", insert(ht, 20));
//	printf("Insert Index list  %d\n", insert(ht, 30));
//	printf("Insert Index list  %d\n", insert(ht, 13));
//	printf("Insert Index list  %d\n", insert(ht, 11));
	printHashTable(ht);


	int i= 100;
	for(i=0; i< 100; i++) {
		insert(ht, random()%2000);
	}


	printf("Search = %d\n", search(ht, 20));
///	printf("Delete = %d\n", delete(ht, 20));

	printHashTable(ht);

	deleteHashTable(ht);
	ht = NULL;

	return 0;
}


