#include <stdio.h>
#include <stdlib.h>

typedef struct tuple {
    int vertex;
    int weight;
    struct tuple *next;
} Tuple;

typedef struct graph {
    int vertices;
    Tuple **adjLists;
} Graph;

Graph* generateGraph(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->vertices = V;
    g->adjLists = malloc(V * sizeof(Tuple*));

    for (int i = 0; i < V; i++) {
        g->adjLists[i] = NULL;
    }

    return g;
}

Tuple* createTuple(int vertex, int weight) {
    Tuple *newTuple = malloc(sizeof(Tuple));
    newTuple->vertex = vertex;
    newTuple->weight = weight;
    newTuple->next = NULL;
    return newTuple;
}

void addEdge(Graph *g, int src, int dest, int weight) {
    Tuple *newNode = createTuple(dest, weight);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

void printGraph(Graph *g) {
    int vertices = g->vertices;
    for (int i = 0; i < vertices; i++) {
        printf("Vertex - %d:\t", i);
        Tuple *adjList = g->adjLists[i];
        while (adjList != NULL) {
            printf("[%d, %d]\t", adjList->vertex, adjList->weight);
            adjList = adjList->next;
        }
        printf("\n");
    }
    printf("\n\n");
}

void freeGraph(Graph *g) {
    int vertices = g->vertices;
    for (int i = 0; i < vertices; i++) {
        Tuple *adjList = g->adjLists[i];
        while (adjList != NULL) {
            Tuple *toFree = adjList;
            adjList = adjList->next;
            free(toFree);
        }
    }
    free(g->adjLists);
    free(g);
}


int main(void){
    printf("Hello, world\n\n");

    Graph* graph = generateGraph(8);

    // for vertex 0;
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 15);
    addEdge(graph, 0, 3, 25);

     // From vertex 1
    addEdge(graph, 1, 0, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 15);
    addEdge(graph, 1, 5, 5);
    
    // From vertex 2
    addEdge(graph, 2, 0, 15);
    addEdge(graph, 2, 1, 1);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 2, 6, 22);
    
    // From vertex 3
    addEdge(graph, 3, 0, 25);
    addEdge(graph, 3, 2, 7);
    addEdge(graph, 3, 6, 12);
    
    // From vertex 4
    addEdge(graph, 4, 1, 15);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 4, 7, 8); 
    
    // From vertex 5
    addEdge(graph, 5, 1, 5);
    addEdge(graph, 5, 2, 6);
    addEdge(graph, 5, 4, 4);
    addEdge(graph, 5, 6, 29);
    addEdge(graph, 5, 7, 12); 
    
    // From vertex 6
    addEdge(graph, 6, 2, 22);
    addEdge(graph, 6, 3, 12);
    addEdge(graph, 6, 5, 29);
    addEdge(graph, 6, 7, 18);
    
    // From vertex 7
    addEdge(graph, 7, 4, 8); 
    addEdge(graph, 7, 5, 12); 
    addEdge(graph, 7, 6, 18);

    printGraph(graph);
    freeGraph(graph);

    return 0;
}