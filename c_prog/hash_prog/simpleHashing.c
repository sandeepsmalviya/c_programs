#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 17
#define EMPTY  -327868
struct HashSet {
	int *hp;
	int size;
};

int insert(struct HashSet *hs, int data);
int delete(struct HashSet *hs, int data);
int search(struct HashSet *hs, int data);


struct HashSet* createHashSet(int hashSize) {

	struct HashSet* hs = (struct HashSet*) malloc(sizeof(struct HashSet));
	int *hp  = (int *) malloc(hashSize * sizeof(int));	
	hs->hp = hp;
	hs->size = hashSize;

	int i=0;
	for(i=0; i < hashSize; i++) {
		(hs->hp)[i] = EMPTY;	
	}

	printf("HashSet created with size = %d ...\n", hs->size);
	return hs;
}

void deleteHashSet(struct HashSet* hs) {

	free(hs->hp);
	free(hs);

	printf("HashSet deleted with size = %d ...\n", hs->size);
}

void printHashSet(struct HashSet *hs) {
	printf("HashSet Contents are...\n");
	printf("Size = %d\n", hs->size);
	printf("Data ...\n");
	int i=0;
	for(i=0; i < (hs->size); i++) {
		printf("[%d] = %d\n", i, hs->hp[i]);
	}
}

int convertToHashCode(int data) {
	return data;
}

int hash(int hashKey, int modSize) {
	//printf("Hash key == %d, size = %d, hash = %d\n", hashKey, modSize, hashKey % modSize);
	return hashKey % modSize;
}

int insert(struct HashSet* hs, int data) {
	int hk = convertToHashCode(data);
	int hi =  hash(hk, hs->size);
	
	
	if((hs->hp)[hi] == EMPTY) {
		(hs->hp)[hi] = data;
		return hi;
	}else {
		printf("Hash Collision, Cant insert ...%d at %d\n", data, hi);
		return -1;
	}
}

int search(struct HashSet* hs, int data) {
	int hk = convertToHashCode(data);
	int hi =  hash(hk, hs->size);
	
	if((hs->hp)[hi] == EMPTY) {
		
		//printf("Element = %d not found ...\n", data);
		return -1;
	}else {
		//printf("Search Element = %d found at location %d ...\n", data, hi);
		return hi;
	}
}


int delete(struct HashSet* hs, int data) {
	int hk = convertToHashCode(data);
	int hi =  hash(hk, hs->size);
	
	if((hs->hp)[hi] == EMPTY) {
		
		//printf("Element = %d not found, Can't delete ...\n", data);
		return -1;
	}else {
		//printf("Delete Element = %d found at location %d ...\n", data, hi);
		hs->hp[hi] = EMPTY;
		return hi;
	}
}

int main() {
	struct HashSet *hs = createHashSet(HASH_SIZE);

	printf("Insert = %d\n", insert(hs, 10));
	printf("Insert = %d\n", insert(hs, 20));
	printf("Insert = %d\n", insert(hs, 30));
	printf("Insert = %d\n", insert(hs, 10));
	
	printf("Search = %d\n", search(hs, 20));
	printf("Delete = %d\n", delete(hs, 20));


	printHashSet(hs);
	deleteHashSet(hs);

	return 0;
}


