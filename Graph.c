#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH_NODE_s *GRAPH_NODE;

typedef struct GRAPH_NODE_s
{
	int vertex;
	GRAPH_NODE* next;
}GRAPH_NODE_t[1];

typedef struct GRAPH_s *GRAPH;

typedef struct GRAPH_s
{
	int numVertices;
	int* visited;
	GRAPH_NODE** adjLists;
}GRAPH_t[1];

GRAPH_NODE createNode(int v);

GRAPH createGraph(int);
void addEdge(GRAPH, int, int);
void printGraph(GRAPH);
void DFS(GRAPH, int);


int main()
{

	GRAPH g = createGraph(4);
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 1, 2);
	addEdge(g, 2, 3);

	printGraph(g);

	DFS(g,2);

	return 0;
}

void DFS(GRAPH g, int v) {
	GRAPH_NODE adjList = graph->adjLists[v];
	GRAPH_NODE temp = adjList;

	g->visited[v] = 1;
	printf("Visited %d \n",v);

	while (temp != NULL) {
		int connectedVertex = temp->v;

		if (graph->visited[connectedVertex] == 0) {
			DFS(graph, connectedVertex);
		}
		temp = temp->next;
	}
}


GRAPH_NODE createNode(int v1)
{
	GRAPH_NODE newNode = malloc(sizeof(GRAPH_NODE));
	newNode->vertex = v1;
	newNode->next = NULL;
	return newNode;
}

GRAPH createGraph(int v2)
{
	GRAPH graph = malloc(sizeof(GRAPH));
	graph->numVertices = v2;

	graph->adjLists = malloc(v2 * sizeof(GRAPH_NODE));

	graph->visited = malloc(v2 * sizeof(int));

	int i;
	for (i = 0; i < v2; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

void addEdge(GRAPH g, int src, int dest)
{
	// Add edge from src to dest
	GRAPH_NODE newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	g->adjLists[src] = newNode;

	// Add edge from dest to src
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	g->adjLists[dest] = newNode;
}

void printGraph(GRAPH g)
{
	int v3;
	for (v3 =0;v3<g->numVertices;v++)
	{
		GRAPH_NODE temp = g>adjLists[v3];
		printf("\n Adjacency list of vertex %d\n ", v3);
		while (temp)
		{
			printf("%d -> ", temp->v3);
			temp = temp->next;
		}
		printf("\n");
	}
}