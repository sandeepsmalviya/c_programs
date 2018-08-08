#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct graph {
	int V;
	int E;
	int **adjMatrix;
};

struct graph* createGraph(int V, int E);
struct graph* createDirectedGraph(int V, int E);
struct graph* createWeightedGraph(int V, int E);
struct graph* createWeightedDirectedGraph(int V, int E);

void printDegreeOfNode(struct graph *g, int v);
void printDegreeOfNodes(struct graph *g);

int main() {

	int V,E;
	printf("Plz enter no of vertices:\n");
	scanf("%d", &V);
	
	
	printf("Plz enter no of Edges:\n");
	scanf("%d", &E);

	
	//struct graph *g = createGraph(V, E);
	//struct graph *g = createDirectedGraph(V, E);
	//struct graph *g = createWeightedGraph(V, E);
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

	
	printDegreeOfNode(g, 3);
	printDegreeOfNodes(g);
	return 0;
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



struct graph * createWeightedGraph(int V, int E) {
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


void printDegreeOfNode(struct graph *g, int v) {
	
	int d = 0;
	for(int i=0; i< (g->V); i++) {
		if(g->adjMatrix[v][i] !=0 && g->adjMatrix[v][i] != INF) {
			d = d+1;
		}
	}

	printf("Degree of Vertex=%d is %d\n", v, d);

}

void printDegreeOfNodes(struct graph *g) {
	

	for(int v=0; v < (g->V); v++) {
		int d = 0;
		for(int i=0; i< (g->V); i++) {
			if(g->adjMatrix[v][i] !=0 && g->adjMatrix[v][i] != INF) {
				d = d+1;
			}
		}
		printf("Degree of Vertex=%d is %d\n", v, d);
	}
}
