#include <stdio.h>

#define MAX 100

typedef struct stack {
    int arr[MAX];
    int top;
} Stack;

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    }

    return s->arr[s->top];
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
    } else {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    }

    int val = s->arr[s->top];
    (s->top)--;
    return val;
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int main(void){
    printf("Hello, world\n\n");

    Stack st;
    st.top = -1;

    Stack *s = &st;

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    display(s);

    printf("%d\n", peek(s));
    push(s, 50);
    display(s);

    pop(s);
    pop(s);
    display(s);

    return 0;
}