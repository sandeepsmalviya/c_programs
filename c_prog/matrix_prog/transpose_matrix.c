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

int** transposeMatrix(int** matrix1, int r, int c) {
	int **matrix_transpose = createMatrix(c,r);
	int i,j;		
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {	
			matrix_transpose[j][i] = matrix1[i][j];
		}
	}
	return matrix_transpose;
}


int main(int argc, char *argv[]) {
	
	if(argc !=3 ) {
		printf("Usage:\n<program_name> <rows> <columns>\n");
		return -1;
	}
	int r=atoi(argv[1]);
	int c=atoi(argv[2]);

	int **matrix1 = createMatrix(r,c);
	printf("Matrix 1 :\n");
	initMatrix(matrix1, r,c);
	displayMatrix(matrix1, r,c);


	printf("Transpose of Matrix :\n");
	int** matrix_transpose = transposeMatrix(matrix1, r, c);
	deleteMatrix(matrix1,r,c);
	displayMatrix(matrix_transpose, c,r);
	deleteMatrix(matrix_transpose,c,r);

	return 0;
}
