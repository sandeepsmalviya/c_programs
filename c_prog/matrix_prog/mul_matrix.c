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
			matrix[i][j] = random()%5;
		}
	}
}

int** mulMatrix(int** matrix1, int r1, int c1, int **matrix2, int r2, int c2) {
	int **matrix3 = createMatrix(r1,c2);
	int i,j,k;		
	int sum;
	for(i=0; i<r1; i++) {
		for(j=0; j<c2; j++) {
			sum = 0;
			for(k=0; k<c1; k++) {		
				sum = sum + matrix1[i][k] * matrix2[k][j];
			}
			matrix3[i][j] = sum;
		}
	}
	return matrix3;
}


int main(int argc, char *argv[]) {
	
	if(argc !=5 ) {
		printf("Usage:\n<program_name> <row1> <column1> <row2> <colum2>\n");
		return -1;
	}
	int r1=atoi(argv[1]);
	int c1=atoi(argv[2]);
	int r2=atoi(argv[3]);
	int c2=atoi(argv[4]);

	if(c1 != r2) {
		printf("Error:First matrix columns must be equal to seconds matrix rows ...\n");
		return -2;
	}

	int **matrix1 = createMatrix(r1,c1);
	int **matrix2 = createMatrix(r2,c2);
	printf("Matrix 1 :\n");
	initMatrix(matrix1, r1,c1);
	displayMatrix(matrix1, r1,c1);

	printf("Matrix 2 :\n");
	initMatrix(matrix2, r2,c2);
	displayMatrix(matrix2, r2,c2);

	int **mul_matrix3 = mulMatrix(matrix1, r1, c1, matrix2, r2, c2);
	deleteMatrix(matrix1,r1,c1);
	deleteMatrix(matrix2,r2,c2);
	printf("\nMultiplication Matrix 3 :\n");
	displayMatrix(mul_matrix3, r1, c2);
	deleteMatrix(mul_matrix3,r1,c2);

	return 0;
}
