#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node Node;

Node* createLLNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

int find(Node *head, int val) {
    if (head == NULL) return 0;

    Node *temp = head;
    while(temp->next != NULL) { // wont check last node 
        if (temp->val == val) return 1;
        temp = temp->next;
    }

    return 0;
}


void removeLast(Node* first) { 
    if (first == NULL) return;           // empty list
    
    if (first->next == NULL) {           // single node
        free(first);
        first = NULL;
        return;
    }

    Node *p, *q;            // atleast 2 or more nodes
    p = first; 
    q = p->next; 
    while (q->next != NULL) {
        p = q;
        q = q->next;
    }
    p->next = NULL; 
    free(q);
}

int main(void){
    printf("Hello, world\n\n - Linked List Practice Set 1\n\n");

    Node *ll1 = createLLNode(1);
    ll1->next = createLLNode(6);
    ll1->next->next = createLLNode(9);
    ll1->next->next->next = createLLNode(13);

    Node *temp = ll1;
    while (temp != NULL) {
        printf("%d - %d\n", temp->val, find(ll1, temp->val));
        temp = temp->next;
    }

    while (ll1 != NULL) {
        Node *tempNext = ll1->next;
        free(ll1);
        ll1 = tempNext;
    }

    return 0;
}