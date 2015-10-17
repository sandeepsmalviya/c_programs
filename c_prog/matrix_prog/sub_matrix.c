#include<stdio.h>
#include<stdlib.h>

int** createMatrix(int r, int c) {
	int **matrix = (int**)malloc(r * sizeof(int *));
	int i;
	for(i=0; i< r; i++) {
		matrix[i] = (int *)malloc(c * sizeof(int));
	}
	return matrix;
}


void deleteMatrix(int **matrix, int r, int c) {
	int i;

	for(i=0; i<r; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void displayMatrix(int** matrix, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {	
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void initMatrix(int** matrix, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {	
			matrix[i][j] = random()%100;
		}
	}
}


int** subMatrix(int** matrix1, int **matrix2, int r, int c) {
	int **matrix3 = createMatrix(r,c);
	int i,j;		
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {	
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
			//printf("%d =  %d + %d\n", matrix3[i][j],matrix1[i][j] , matrix2[i][j]);
		}
	}
	return matrix3;
}

int main(int argc, char *argv[]) {
	
	if(argc !=3 ) {
		printf("Usage:\n<program_name> <rows> <columns>\n");
		return -1;
	}
	int r=atoi(argv[1]);
	int c=atoi(argv[2]);

	int **matrix1 = createMatrix(r,c);
	int **matrix2 = createMatrix(r,c);
	printf("Matrix 1 :\n");
	initMatrix(matrix1, r,c);
	displayMatrix(matrix1, r,c);

	printf("Matrix 2 :\n");
	initMatrix(matrix2, r,c);
	displayMatrix(matrix2, r,c);

	int **sub_matrix3 = subMatrix(matrix1, matrix2, r, c);
	deleteMatrix(matrix1,r,c);
	deleteMatrix(matrix2,r,c);

	printf("\nSub Matrix 3 :\n");
	displayMatrix(sub_matrix3, r, c);
	deleteMatrix(sub_matrix3,r,c);


	return 0;
}
