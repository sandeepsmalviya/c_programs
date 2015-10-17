#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 11
#define EMPTY  -32768
#define DELETED -32767

struct HashSet {
	int *hp;
	int size;
	int table_size;
	
};

int insert(struct HashSet *hs, int data);
int delete(struct HashSet *hs, int data);
int search(struct HashSet *hs, int data);


struct HashSet* createHashSet(int tableSize) {

	struct HashSet* hs = (struct HashSet*) malloc(sizeof(struct HashSet));
	int *hp  = (int *) malloc(tableSize * sizeof(int));	
	hs->hp = hp;
	hs->table_size = tableSize;
	hs->size = 0;

	int i=0;
	for(i=0; i < hs->table_size; i++) {
		(hs->hp)[i] = EMPTY;	
	}

	printf("HashSet created with table size = %d ...\n", hs->table_size);
	return hs;
}

void deleteHashSet(struct HashSet* hs) {

	free(hs->hp);
	free(hs);

	printf("HashSet deleted with table size = %d ...\n", hs->table_size);
}

void printHashSet(struct HashSet *hs) {
	printf("HashSet Contents are...\n");
	printf("Size = %d\n", hs->table_size);
	printf("Data ...\n");
	int i=0;
	for(i=0; i < (hs->table_size); i++) {
		printf("[%d] = %d\n", i, hs->hp[i]);
	}
}

int convertToHashCode(int data) {
	return data;
}

int hash(int hashKey, int tableSize) {
	//printf("Hash key == %d, size = %d, hash = %d\n", hashKey, modSize, hashKey % modSize);
	return hashKey % tableSize;
}

int insert(struct HashSet* hs, int data) {

	int hk = convertToHashCode(data);

	int hi =  hash(hk, hs->table_size);
	
	int i=0;
	while(i < hs->table_size) {
		i++;

		if((hs->hp)[hi] == EMPTY ||  (hs->hp)[hi] == DELETED) {
			(hs->hp)[hi] = data;
			hs->size = hs->size + 1;
			return hi;
	
		} else {
			hk = hi + i*i;
			hi = hash(hk, hs->table_size);		
		}
	}

	printf("Hash Table is full, Cant insert ...%d\n", data);
	return -1;
}

int search(struct HashSet* hs, int data) {

	int hk = convertToHashCode(data);

	int hi =  hash(hk, hs->table_size);
	
	int i=0;
	while(i < hs->table_size && (hs->hp)[hi] != EMPTY) {
		i++;

		if((hs->hp)[hi] == data) {
			(hs->hp)[hi] = data;
			return hi;
		} else {
			hk = hi + i*i;
			hi = hash(hk, hs->table_size);		
		}
	}

	return -1;
}



int delete(struct HashSet* hs, int data) {

	int hk = convertToHashCode(data);
	int hi =  hash(hk, hs->table_size);

	int i=0;
	while(i < hs->table_size && (hs->hp)[hi] != EMPTY) {
		i++;

		if((hs->hp)[hi] == data) {
			(hs->hp)[hi] = DELETED;
			hs->size = hs->size - 1;
			return hi;
		} else {
			hk = hi + i*i;
			hi = hash(hk, hs->table_size);		
		}
	}

	return -1;
}


int main() {
	struct HashSet *hs = createHashSet(HASH_SIZE);

	int i = 0;

	for(i=0; i < 12; i++) {		
		insert(hs, 10*(i+1));
	}

	printHashSet(hs);

	hs->hp[4] = DELETED;
	hs->hp[5] = DELETED;
	hs->hp[8] = DELETED;
//	hs->hp[9] = DELETED;
	printHashSet(hs);

	insert(hs, 110);
	insert(hs, 119);
	printHashSet(hs);

	int item = 119;
	int s = search(hs, item);
	printf("Item %d found at index = %d\n", item, s);


	item = 117;
	s = search(hs, item);
	printf("Item %d found at index = %d\n", item, s);


	item = 100;
	s = search(hs, item);
	printf("Item %d found at index = %d\n", item, s);


	item = 100;
	s = delete(hs, item);
	printf("Item %d deleted at index = %d\n", item, s);
	
	printHashSet(hs);


	item = 40;
	s = delete(hs, item);
	printf("Item %d deleted at index = %d\n", item, s);
	
	printHashSet(hs);
	deleteHashSet(hs);
	return 0;
}


