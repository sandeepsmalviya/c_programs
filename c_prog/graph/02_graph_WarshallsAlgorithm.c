#include<stdio.h>
#include<stdlib.h>

#define INF 9999

#define TRUE 1
#define FALSE 0

struct graph {
	int V;
	int E;
	int **adjMatrix;
};

struct graph* createGraph(int V, int E);
struct graph* createDirectedGraph(int V, int E);


//gives reachability from node u to node v exsts or not
int** warshallsAlgorithm(struct graph* g);

int main() {

	int V,E;
	printf("Plz enter no of vertices:\n");
	scanf("%d", &V);
	
	
	printf("Plz enter no of Edges:\n");
	scanf("%d", &E);

	
	//struct graph *g = createGraph(V, E);
	struct graph *g = createDirectedGraph(V, E);


	printf("Graph Vertices = %d, Edges=%d\n", g->V, g->E);

	printf("Adjacency Matrix : \n");
	for(int i=0; i<(g->V); i++) {			
		for(int j=0; j<(g->V); j++) {

			if(g->adjMatrix[i][j] == INF) {				
				printf("%7s\t","INF");
			}else {
				printf("%7d\t",g->adjMatrix[i][j]);
			}

		}
		printf("\n");
	}

	
	printDegreeOfNode(g, 3);
	printDegreeOfNodes(g);

	int** warshallsPath = warshallsAlgorithm(g);
	
	printf("Warshalls output:\n");
	for (int i = 0; i < (g->V); i++) {
		for (int j = 0; j < (g->V); j++) {
			printf("%7d\t", warshallsPath[i][j]);
		}
		printf("\n");
	}

	return 0;
}


int** warshallsAlgorithm(struct graph* g)
{

	int  i, j, k;
	
	//create memory for warshalls path
	int** path = (int **) malloc(sizeof(int) * (g->V));
	for(i=0; i<(g->V); i++) {					
		path[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {
			path[i][j] = 0;
		}
	}

	//initialize for warshalls path from graph adjacency matrix
	for (i = 0; i < (g->V); i++) {
		for (j = 0; j < (g->V); j++) {
			path[i][j] = g->adjMatrix[i][j];
		}
	}

	//apply warshalls algorithm for path
	for(k=0; k< (g->V); k++) {
		for(i=0; i<(g->V); i++) {
			if(path[i][k] == TRUE) {
				for(j=0; j<(g->V); j++) {
					path[i][j] = path[i][j] || path[k][j];
				}
			}
		}
	}

	return path;
}


struct graph * createGraph(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V));

	for(int i=0; i<(g->V); i++) {					
		g->adjMatrix[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {
			g->adjMatrix[i][j] = 0;
		}
	}


	for(int i=0; i<(g->E); i++) {					
		int u, v;
		printf("Enter source and destination edges\n");
		scanf("%d %d", &u, &v);
		
		g->adjMatrix[u][v] = 1;
		g->adjMatrix[v][u] = 1;
	}

	return g;
}




struct graph * createDirectedGraph(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V));

	for(int i=0; i<(g->V); i++) {					
		g->adjMatrix[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {
			g->adjMatrix[i][j] = 0;
		}
	}


	for(int i=0; i<(g->E); i++) {					
		int u, v;
		printf("Enter source and destination edges\n");
		scanf("%d %d", &u, &v);
		
		g->adjMatrix[u][v] = 1;
	}

	return g;
}

