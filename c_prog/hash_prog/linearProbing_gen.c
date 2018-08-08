#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 10
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

		if(hs->hp[i] == EMPTY) {
			printf("[%d] = EMPTY\n", i);
		} else if(hs->hp[i] == DELETED) {
			printf("[%d] = DELETED\n", i);
		}else {
			printf("[%d] = %d\n", i, hs->hp[i]);
		}
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

	int hashCode = convertToHashCode(data);
	int hi_initial =  hash(hashCode, hs->table_size);
	int hi=0;
	int hk=0;

	int i=0;
	while(i < hs->table_size) {

		hk = hi_initial + i;
		hi = hash(hk, hs->table_size);		
		
		if((hs->hp)[hi] == EMPTY ||  (hs->hp)[hi] == DELETED) {
			(hs->hp)[hi] = data;
			hs->size = hs->size + 1;
			return hi;	
		}
		i++;
	}
	printf("Hash Table is full, Cant insert ...%d\n", data);
	return -1;
}

int search(struct HashSet* hs, int data) {

	int hashCode = convertToHashCode(data);
	int hi_initial =  hash(hashCode, hs->table_size);
	int hi =  hi_initial;
	int hk=0;
	
	int i=0;
	while(i < hs->table_size) {

		hk = hi_initial + i;
		hi = hash(hk, hs->table_size);		

		if((hs->hp)[hi] == EMPTY) {
			break;
		}

		if((hs->hp)[hi] == data) {
			(hs->hp)[hi] = data;
			return hi;
		}
		
		i++;
	}

	return -1;
}



int delete(struct HashSet* hs, int data) {

	int hashCode = convertToHashCode(data);
	int hi_initial =  hash(hashCode, hs->table_size);
	int hi =  hi_initial;
	int hk=0;

	int i=0;
	while(i < hs->table_size) {

		hk = hi_initial + i;
		hi = hash(hk, hs->table_size);		

		
		if((hs->hp)[hi] == EMPTY) {
			break;
		}
		if((hs->hp)[hi] == data) {
			(hs->hp)[hi] = DELETED;
			hs->size = hs->size - 1;
			return hi;
		} 

		i++;
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

	delete(hs, 40);
	delete(hs, 50);
	delete(hs, 80);
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


