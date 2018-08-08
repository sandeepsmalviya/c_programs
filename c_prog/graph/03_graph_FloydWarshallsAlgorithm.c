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

struct graph* createWeightedGraph(int V, int E);
struct graph* createWeightedDirectedGraph(int V, int E);

//gives all pairs shortest path
int** floydWarshallsAlgorithm(struct graph* g);

int main() {

	int V,E;
	printf("Plz enter no of vertices:\n");
	scanf("%d", &V);
	
	
	printf("Plz enter no of Edges:\n");
	scanf("%d", &E);

	
	//struct graph *g = createGraph(V, E);
	struct graph *g = createWeightedDirectedGraph(V, E);


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

	int** floydWarshallsPath = floydWarshallsAlgorithm(g);
	
	printf("Floyd Warshalls output:\n");
	for (int i = 0; i < (g->V); i++) {
		for (int j = 0; j < (g->V); j++) {

			if(floydWarshallsPath[i][j] == INF) {				
				printf("%7s\t","INF");
			}else {
				printf("%7d\t",floydWarshallsPath[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}


int** floydWarshallsAlgorithm(struct graph* g)
{

	int  i, j, k;
	
	//create memory for warshalls path
	int** dist = (int **) malloc(sizeof(int) * (g->V));
	for(i=0; i<(g->V); i++) {					
		dist[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {
			dist[i][j] = 0;
		}
	}

	//initialize for warshalls path from graph adjacency matrix
	for (i = 0; i < (g->V); i++) {
		for (j = 0; j < (g->V); j++) {
			dist[i][j] = g->adjMatrix[i][j];
		}
	}

	//apply warshalls algorithm for path
	for(k=0; k< (g->V); k++) {
		for(i=0; i<(g->V); i++) {			
			for(j=0; j<(g->V); j++) {

				if (dist[i][k] + dist[k][j] < dist[i][j]) {
		                	dist[i][j] = dist[i][k] + dist[k][j];
				}
			}			
		}
	}

	return dist;
}


struct graph * createWeightedGraph(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V));

	for(int i=0; i<(g->V); i++) {					
		g->adjMatrix[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {

			if(i==j) {
				g->adjMatrix[i][j] = 0;
			}else {
				g->adjMatrix[i][j] = INF;
			}
		}
	}


	for(int i=0; i<(g->E); i++) {					
		int u, v, w;
		printf("Enter source, destination edges and weight : \n");
		scanf("%d %d %d", &u, &v, &w);
		
		g->adjMatrix[u][v] = w;
		g->adjMatrix[v][u] = w;
	}

	return g;
}

struct graph * createWeightedDirectedGraph(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V));

	for(int i=0; i<(g->V); i++) {					
		g->adjMatrix[i] = (int *) malloc(sizeof(int) * (g->V));
		for(int j=0; j<(g->V); j++) {
			if(i==j) {
				g->adjMatrix[i][j] = 0;
			}else {
				g->adjMatrix[i][j] = INF;
			}
		}
	}


	for(int i=0; i<(g->E); i++) {					
		int u, v, w;
		printf("Enter source, destination edges and weight : \n");
		scanf("%d %d %d", &u, &v, &w);
		
		g->adjMatrix[u][v] = w;
	}

	return g;
}

