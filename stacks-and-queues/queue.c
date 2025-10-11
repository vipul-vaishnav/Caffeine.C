#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int size;
    int front;
    int rear;
    int *arr;
    unsigned int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *qu = malloc(sizeof(Queue));
    qu->front = -1; 
    qu->rear = -1;
    qu->capacity = capacity;
    qu->arr = malloc(capacity * sizeof(int));
    qu->size = 0;
    return qu;
}

bool isFull(Queue *qu) {
    return qu->size == qu->capacity;
}

bool isEmpty(Queue *qu) {
    return qu->size == 0;
}

void add(Queue *qu, int value) {
    if (isFull(qu)) {
        printf("Queue is Full!");
        return;
    }

    if (isEmpty(qu)) {
        qu->front = 0;
        qu->rear = 0;
    } else {
        int rPos = (qu->rear + 1) % qu->capacity;
        qu->rear = rPos;
    }

    (qu->size)++;
    (qu->arr)[qu->rear] = value;
    printf("Element added!!\n\n");
}

int poll(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Cannot poll from an empty queue!");
        return -1;
    } else {
        int value = (qu->arr)[qu->front];
        (qu->size)--;

        if (qu->size == 0) {
            qu->front = -1;
            qu->rear = -1;
        } else {
            qu->front = (qu->front + 1) % qu->capacity;
        }
        
        return value;
    }
}

int peek(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is Empty!");
        return -1;
    } else {
        return (qu->arr)[qu->front];
    }
}

void printQueue(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is empty!\n");
        return;
    }

    for (int i = 0; i < qu->size; i++) {
        int pos = (qu->front + i) % qu->capacity;
        printf("%d ", qu->arr[pos]);
    }
    printf("\n");
}

void destroyQueue(Queue *qu) {
    free(qu->arr);
    free(qu);
}


int getSize(Queue *qu) {
    return qu->size;
}

int main(void){
    printf("Hello, world\n\nQueue Implementation:\n\n");

    Queue *qu = createQueue(5);
    
    add(qu, 10);
    add(qu, 20);
    add(qu, 30);
    add(qu, 40);

    printQueue(qu);

    printf("Front: %d\n", peek(qu));
    printf("Dequeued: %d\n", poll(qu));
    printf("Dequeued: %d\n", poll(qu));

    printQueue(qu);

    add(qu, 50);
    add(qu, 60);
    printQueue(qu);

    destroyQueue(qu);
    return 0;
}