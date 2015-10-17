#include<stdio.h>
#include<string.h>

#define NUM 5
struct vertex {
	
	char name[10];
	int index;
	
};

struct edge {
	
	int weight;
	struct vertex* source;
	struct vertex* destination;
	int adjacency;
};

struct graph {
	
	struct vertex* v[NUM];
	struct edge e[NUM][NUM];
	
};

void addEdge(struct graph *g, struct edge e) {

	printf("s=%d\td=%d e= %d\n",e.source->index, e.destination->index, e.adjacency);	
	g->e[e.source->index][e.destination->index]=e;
				
} 
int main() {
	
	struct graph g;
	
	struct vertex av,bv,cv,dv,ev;
	strcpy(av.name, "A");
	strcpy(bv.name, "B");
	strcpy(cv.name, "C");
	strcpy(dv.name, "D");
	strcpy(ev.name, "E");

	av.index=0;
	bv.index=1;
	cv.index=2;
	dv.index=3;
	ev.index=4;



	g.v[0] = &av;
	g.v[1] = &bv;
	g.v[2] = &cv;
	g.v[3] = &dv;
	g.v[4] = &ev;
			
	
	struct edge e1;
	e1.weight = 1;
	e1.source = &av;
	e1.destination = &bv;
	e1.adjacency = 1;
	
	
	addEdge(&g, e1);

	
	printf("Edge between a and b = %d\n", g.e[e1.source->index][e1.destination->index].adjacency);
	printf("Hello\n");

	return 0;

}
