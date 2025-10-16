#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element {
    int val;
    struct element *next;
};

typedef struct element Element;

struct stack {
    int size;
    Element *top;
};

typedef struct stack Stack;

Stack* createStack() {
    Stack *s = (Stack*) (malloc(sizeof(Stack)));
    s->size = 0;
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

int getSize(Stack *s) {
    return s->size;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!");
        return -1;
    }

    return s->top->val;
}

bool push(Stack *s, int val) {
    Element *el = (Element*) (malloc(sizeof(Element)));
    el->val = val;
    el->next = NULL;

    if (isEmpty(s)) {
        s->top = el;
    } else {
        el->next = s->top;
        s->top = el;
    }

    s->size++;
    return true;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!");
        return -1;
    } else {
        s->size--;

        Element *el = s->top;
        int val = el->val;
        s->top = el->next;
        free(el);

        return val;
    }
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!");
        return;
    } else {
        Element *top = s->top;

        while (top != NULL) {
            printf("%d\t", top->val);
            top = top->next;
        }

        printf("\n");
    }
}

int main(void){
    printf("Hello, world\n\n");

    Stack *s = createStack();

    if (isEmpty(s)) {
        printf("Empty!\n\n");
    }

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    printStack(s);
    printf("size: %d\n", getSize(s));

    pop(s);

    printStack(s);
    printf("size: %d\n", getSize(s));

    Element *top = s->top;

    while (top != NULL) {
        Element *topNext = top->next;
        free(top);
        top = topNext;
    }

    free(s);

    printf("\n");
    return 0;
}