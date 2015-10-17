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

void getUserMatrix(int** matrix, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {	
			int num = 0;
			scanf("%d", &num);
			matrix[i][j] = num;
		//	matrix[i][j] = random()%100;
		}
		printf("\n");
	}
}

int** augMatrix(int** matrix1, int r1, int c1, int **matrix2, int r2, int c2) {

	int r3 = r1;
	int c3 = c1 + c2;
	int **matrix3 = createMatrix(r3,c3);
	int i,j;		
	for(i=0; i<r3; i++) {
		for(j=0; j<c1; j++) {	
			matrix3[i][j] = matrix1[i][j];
		}	
		for(j=c1; j<c3; j++) {	
			int c = j - c1;
			matrix3[i][j] = matrix2[i][c];
		}
	}

	return matrix3;
}


int main(int argc, char *argv[]) {
	
	if(argc != 5) {
		printf("Usage:\n<program_name> <rows> <columns> <aug_rows> <aug_columns>\n");
		return -1;
	}

	
	int r1=atoi(argv[1]);
	int c1=atoi(argv[2]);

	
	int r2=atoi(argv[3]);
	int c2=atoi(argv[4]);


	if(r1 != r2) {
		printf("\n Number of rows of both matrix should be same %d != %d", r1, r2);
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


	int **aug_matrix3 = augMatrix(matrix1, r1, c1, matrix2, r2, c2);
	deleteMatrix(matrix1,r1,c1);
	deleteMatrix(matrix2,r2,c2);

	int r3 = r1;
	int c3 = c1 + c2;
	printf("\nSum Matrix 3 :\n");
	displayMatrix(aug_matrix3, r3, c3);
	deleteMatrix(aug_matrix3,r3,c3);

	return 0;
}
