#include <stdio.h>
#include <stdlib.h>
#include "pq-for-edge-weight-tuple.c"
#include <limits.h>

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

void dijkstra(Graph *g, int src) {
    PriorityQueue *pq = initPq(minHeapCmp);

    int vertices = g->vertices;
    int dist[vertices];
    int parent[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    offer(pq, src, 0);
    dist[src] = 0;

    while (!isEmpty(pq)) {
        PQTuple *pqt = poll(pq);
        int dt = pqt->weight;
        int v = pqt->vertex;

        Tuple *nbr = g->adjLists[v];
        while (nbr != NULL) {
            int w = nbr->weight;
            int u = nbr->vertex;

            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                parent[u] = v;

                offer(pq, u, dist[u]);
            }

            nbr = nbr->next;
        }
    }

    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d\tDistance: %d, Parent: %d\n", i, dist[i], parent[i]);
    }
}

int main(void){
    printf("Hello, world\n\n");

    Graph* graph = generateGraph(8);

    // for vertex 0;
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 15);
    addEdge(graph, 0, 3, 25);

     // From vertex 1
    addEdge(graph, 1, 4, 15);
    addEdge(graph, 1, 5, 5);
    
    // From vertex 2
    addEdge(graph, 2, 1, 1);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 6, 22);
    
    // From vertex 3
    addEdge(graph, 3, 6, 12);
    
    // From vertex 4
    addEdge(graph, 4, 7, 8); 
    
    // From vertex 5
    addEdge(graph, 5, 2, 6);
    addEdge(graph, 5, 4, 4);
    addEdge(graph, 5, 6, 29);
    addEdge(graph, 5, 7, 12); 
    
    // From vertex 6
    // addEdge(graph, 6, 2, 22);
    // addEdge(graph, 6, 3, 12);
    // addEdge(graph, 6, 5, 29);
    // addEdge(graph, 6, 7, 18);
    
    // From vertex 7
    // addEdge(graph, 7, 4, 8); 
    // addEdge(graph, 7, 5, 12); 
    addEdge(graph, 7, 6, 18);

    printGraph(graph);

    dijkstra(graph, 0);

    freeGraph(graph);

    return 0;
}