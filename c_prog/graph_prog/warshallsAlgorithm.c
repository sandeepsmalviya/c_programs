#include<stdio.h>
#define V 5
#define FALSE 0
#define TRUE  1 
void printSolution(int dist[][V]);
 
void warshallsAlgorithm(int graph[][V], int path[][V])
{

	int  i, j, k;
	
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			path[i][j] =graph[i][j];
		}
	}

	for(k=0; k<V; k++) {

		for(i=0; i<V; i++) {

			if(path[i][k] == TRUE) {
				for(j=0; j<V; j++) {
					path[i][j] = path[i][j] || path[k][j];
				}
			}
		}
	}
}


/* A utility function to print solution */
void printSolution(int path[][V]) {
	int i,j;		
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
}
 
// driver program to test above function
int main()
{

 	int path[V][V];
	int graph[V][V] = {
				{0, 0, 1, 1, 0},
				{0, 0, 1, 0, 0},
				{0, 0, 0, 1, 1},
				{0, 0, 0, 0, 1},
				{0, 0, 0, 1, 0}
			  };
			
	warshallsAlgorithm(graph, path);
	printSolution(path);
	
	return 0;
}
