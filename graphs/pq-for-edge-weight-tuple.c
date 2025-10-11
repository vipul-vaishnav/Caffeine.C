#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct pqtuple {
    int vertex;
    int weight;
} PQTuple;

typedef int (*Comparator)(PQTuple*, PQTuple*);

typedef struct pq {
    PQTuple *arr[MAX];
    int size;
    Comparator cmp;
} PriorityQueue;

PriorityQueue* initPq(Comparator cmp) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    // pq->arr = malloc(MAX * sizeof(PQTuple));
    pq->size = 0;
    pq->cmp = cmp;
    for (int i = 0; i < MAX; i++) {
        pq->arr[i] = NULL;
    }
    return pq;
}

// Min-heap: smallest weight first
int minHeapCmp(PQTuple *a, PQTuple *b) {
    return a->weight - b->weight;
}

// Max-heap: largest weight first
int maxHeapCmp(PQTuple *a, PQTuple *b) {
    return b->weight - a->weight;
}

bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

bool isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

int size(PriorityQueue *pq) {
    return pq->size;
}

PQTuple* peek(PriorityQueue *pq) {
    if (isEmpty(pq)) return NULL;
    return pq->arr[0];
}

PQTuple* createPQTuple(int vertex, int weight) {
    PQTuple *t = malloc(sizeof(PQTuple));
    t->vertex = vertex;
    t->weight = weight;
    return t;
}

bool offer(PriorityQueue *pq, int vertex, int weight) {
    if (isFull(pq)) {
        printf("Queue is Full!");
        return false;
    }

    PQTuple *t = createPQTuple(vertex, weight);
    pq->arr[pq->size] = t;
    pq->size++;

    int childIndex = pq->size - 1;
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0 && pq->cmp(pq->arr[childIndex], pq->arr[parentIndex]) < 0) {
        PQTuple *temp = pq->arr[childIndex];
        pq->arr[childIndex] = pq->arr[parentIndex];
        pq->arr[parentIndex] = temp;
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }

    return true;
}

PQTuple* poll(PriorityQueue *pq) {
    if (isEmpty(pq)) return NULL;

    pq->size--;
    PQTuple *top = pq->arr[0];
    PQTuple *last = pq->arr[pq->size];
    pq->arr[pq->size] = NULL;

    if (!isEmpty(pq) && last != NULL) {
        pq->arr[0] = last;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq->size) {
            int minIndex = parentIndex;

            if (pq->cmp(pq->arr[leftChildIndex], pq->arr[minIndex]) < 0) {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < pq->size &&
          pq->cmp(pq->arr[rightChildIndex], pq->arr[minIndex]) < 0) {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex) break;

            PQTuple *temp = pq->arr[parentIndex];
            pq->arr[parentIndex] = pq->arr[minIndex];
            pq->arr[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    } 

    return top;
}

// int main(void){
//     printf("Hello, world\n\n");

//     PriorityQueue *pq = initPq(minHeapCmp);

//     offer(pq, 1, 50);
//     offer(pq, 2, 20);
//     offer(pq, 3, 30);
//     offer(pq, 4, 40);
//     offer(pq, 5, 10);

//     printf("Top weight: %d\n", peek(pq)->weight); // should print 20 for min-heap

//     return 0;
// }