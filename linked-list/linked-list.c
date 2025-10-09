#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* createLinkedListFromArr(int *arr, int size) {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < size; i++) {
        int el = *(arr + i);
        Node *tempNode = malloc(sizeof(Node));
        // tempnode->val = el;
        // tempnode->next = NULL;
        (*tempNode).val = el;
        (*tempNode).next = NULL;

        if (head == NULL) {
            head = tempNode;
            tail = head;
        } else {
            // tail->next = tempNode;
            (*tail).next = tempNode;
            tail = tempNode;
        }
    }

    return head;
}

void printLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d->", (*head).val);
        head = (*head).next;
        // printf("%d->", head->val);
        // head = head->next;
    }
    printf("NULL");
}

int main(void){
    printf("Hello, world\n\n");
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = createLinkedListFromArr(arr, ARR_SIZE(arr));
    printLinkedList(head);

        // Free memory (optional cleanup)
    Node *temp;
    while (head) {
        temp = head->next;
        free(head);
        head = temp;
    }
    return 0;
    return 0;
}