#include<stdio.h>
#define V 5
#define FALSE 0
#define TRUE  1 
void printSolution(int dist[][V]);
 
void prod(int a[][V], int b[][V], int c[][V] );

void transclose(int graph[][V], int path[][V])
{

	int  i, j, k;
	int newprod[V][V];
	int adjprod[V][V];
	
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			adjprod[i][j] = path[i][j] =graph[i][j];
		}
	}

	for(i=1; i<V; i++) {

		prod(adjprod, graph, newprod);

		for(j=0; j<V; j++) {
			for(k=0; k<V; k++) {
				path[j][k] = path[j][k] || newprod[j][k];
			}
		}
		for(j=0; j<V; j++) {
			for(k=0; k<V; k++) {
				adjprod[j][k] = newprod[j][k];
			}
		}	
	}
}

void prod(int a[][V], int b[][V], int c[][V] ) {
	int i,j,k, val;	
	for (i=0; i<V; i++) {
		for (j=0; j<V; j++) {

			val= FALSE;
			for(k=0; k<V; k++) {
				val = val || (a[i][k] && b[k][j]);				
			}
			c[i][j] = val;
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
			
	transclose(graph, path);
	printSolution(path);
	
	return 0;
}
