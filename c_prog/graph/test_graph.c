#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct graph {
	int V;
	int E;
	int **adjMatrix;
};

struct graph * createGraph(int V, int E);
struct graph* createGraphNew(int V, int E);
//struct graph*createGraphNewVivek(int V, int E);


int main() {

	int V,E;
	printf("Plz enter no of vertices:\n");
	scanf("%d", &V);
	
	
	printf("Plz enter no of Edges:\n");
	scanf("%d", &E);

	
	//struct graph *g = createGraphNewVivek(V, E);
	struct graph *g = createGraphNew(V, E);

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
	return 0;
}

struct graph * createGraphNewVivek(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V) * (g->V));

	for(int i=0; i<(g->V); i++) {					
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

struct graph * createGraphNew(int V, int E) {
	struct graph *g = (struct graph*)malloc(sizeof(struct graph));
	g->V = V;
	g->E = E;

	g->adjMatrix = (int **) malloc(sizeof(int) * (g->V));
	int *matrix = (int *) malloc(sizeof(int) * (g->V) * (g->V));

	for(int i=0; i<(g->V); i++) {					
//		g->adjMatrix[i] = (int *) malloc(sizeof(int) * (g->V));
//		g->adjMatrix[i] = matrix + i*(g->V);
		g->adjMatrix[i] = &matrix[i*(g->V)];
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




