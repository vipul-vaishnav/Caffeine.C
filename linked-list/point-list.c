#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

typedef struct point Point;

struct node {
    Point p;
    struct node *next;
};

typedef struct node Node;

Node* createPointNode(int x, int y) {
    Node *node = malloc(sizeof(Node));
    node->p = (Point) {.x = x, .y = y};
    node->next = NULL;
    return node;
}

int main(void){
    printf("Hello, world\n\n");

    Node *head = createPointNode(4, 7);

    // to access x
    printf("%d, %d\n", head->p.x, (*head).p.x);

    free(head);

    return 0;
}