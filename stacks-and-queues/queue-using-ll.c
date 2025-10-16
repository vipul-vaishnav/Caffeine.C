#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element {
    int val;
    struct element *next;
};
typedef struct element Element;

struct queue {
    int size;
    Element *head;
    Element *tail;
};
typedef struct queue Queue;

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

Element* createElement(int val) {
    Element *el = (Element*) malloc(sizeof(Element));
    el->val = val;
    el->next = NULL;
    return el;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

int getSize(Queue *q) {
    return q->size;
}

bool enqueue(Queue *q, int val) {
    Element *el = createElement(val);
    if (isEmpty(q)) {
        q->head = el;
        q->tail = el;
    } else {
        q->tail->next = el;
        q->tail = el;
    }
    q->size++;
    return true;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }

    Element *head = q->head;
    int val = head->val;
    q->head = head->next;
    free(head);

    q->size--;
    if (q->size == 0) {
        q->tail = NULL;
    }
    return val;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->head->val;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    Element *el = q->head;
    while (el != NULL) {
        printf("%d\t", el->val);
        el = el->next;
    }
    printf("\n");
}

void destroyQueue(Queue *q) {
    Element *el = q->head;
    while (el != NULL) {
        Element *next = el->next;
        free(el);
        el = next;
    }
    free(q);
}

// ---------- TEST CASE ----------
int main(void) {
    printf("Queue test:\n\n");

    Queue *q = createQueue();

    printf("Initially empty? %s\n\n", isEmpty(q) ? "Yes" : "No");

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue contents: ");
    printQueue(q);
    printf("Size: %d\n", getSize(q));

    printf("Front element: %d\n", peek(q));

    printf("\nDequeuing two elements...\n");
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    printf("\nQueue after dequeues: ");
    printQueue(q);
    printf("Size: %d\n", getSize(q));

    destroyQueue(q);

    printf("\nQueue destroyed.\n");
    return 0;
}
