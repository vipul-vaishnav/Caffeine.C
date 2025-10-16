#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue-for-bfs.c"

typedef struct node {
    int v;
    struct node *next;
} Node;

typedef struct graph {
    int vertices;
    bool isDirected;
    Node **adjLists;
} Graph;

Graph* createGraph(int v, bool isDirected) {
    Graph *g = malloc(sizeof(Graph));
    g->vertices = v;
    g->adjLists = malloc(v * sizeof(Node*));
    g->isDirected = isDirected;
    for (int i = 0; i < v; i++) {
        g->adjLists[i] = NULL;
    }
    return g;
}

Node* createNode(int dest) {
    Node *n = malloc(sizeof(Node));
    n->v = dest;
    n->next = NULL;
    return n;
}

void insertEdge(Graph *g, int src, int dest) {
    bool isDirected = g->isDirected;

    Node *n = createNode(dest);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;
    
    if (!isDirected) { // add dest to src edge is graph is not directed
        Node *n2 = createNode(src);
        n2->next = g->adjLists[dest];
        g->adjLists[dest] = n2;
    }
}

void freeGraph(Graph *g) {
    Node **adjLists = g->adjLists;

    for (int i = 0; i < g->vertices; i++) {
        Node *temp = g->adjLists[i];

        while (temp != NULL) {
            Node *tempCpy = temp;
            temp = temp->next;
            free(tempCpy);
        }
    }

    free(adjLists);
    free(g);
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertext %d :\t", i);
        Node *n = g->adjLists[i];
        while (n != NULL) {
            printf("%d->", n->v);
            n = n->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

void dfsHelper(Graph *g, bool *visited, int i) {
    visited[i] = true;
    printf("%d->", i);

    Node *nbr = g->adjLists[i];

    while (nbr != NULL) {
        int v = nbr->v;
        if (!visited[v]) dfsHelper(g, visited, v);
        nbr = nbr->next;
    }
}

void dfs(Graph *g) {
    int size = g->vertices;
    bool visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            dfsHelper(g, visited, i);
            printf("NULL\n");
        }
    }

    printf("\n");
}

int main(void){
    printf("Hello, world\n\n");

    Graph *g = createGraph(6, false);

    // 0, 1, 2, 3, 4, 5

    insertEdge(g, 0, 1);
    insertEdge(g, 0, 2);

    insertEdge(g, 1, 5);
    insertEdge(g, 1, 4);

    insertEdge(g, 2, 3);

    insertEdge(g, 3, 5);

    insertEdge(g, 4, 2);

    insertEdge(g, 5, 4);

    printGraph(g);

    dfs(g);

    freeGraph(g);

    return 0;
}