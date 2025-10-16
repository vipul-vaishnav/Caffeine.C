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

Node* createNode(int val) {
    Node *n = malloc(sizeof(Node));
    n->next = NULL;
    n->val = val;
    return n;
}

Node* insertAtStart(Node *head, int data) {
    Node *n = createNode(data);

    if (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head = n;
    }

    return head;
}

Node* deleteAtStart(Node *head) {
    if (head == NULL) return NULL;

    Node *temp = head->next;
    Node *tempHead = head;
    head = temp;
    free(tempHead);
    return head;
}

Node* deleteAtEnd(Node *head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *tempNext = temp->next;
    temp->next = NULL;
    free(tempNext);

    return head;
}

Node* insertRear(Node *head, int data) {
    if (head == NULL) {
        Node *n = createNode(data);
        return n;
    } else {
        head->next = insertRear(head->next, data);
        return head;
    }
}

Node* deleteRear(Node *head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        head->next = deleteRear(head->next);
        return head;
    }
}

Node* deleteAllOccurances(Node* head, int x) {
    if (head == NULL) return NULL;
    else {
        if (head->data == x) {
            return deleteAllOccurances(head->next, x);
        } else {
            head->next = deleteAllOccurances(head->next, x);
            return head;
        }
    }
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
    
    head = insertRear(head, 6);
    head = insertRear(head, 7);
    head = insertRear(head, 8);

    head = insertAtStart(head, 99);
    head = insertAtStart(head, -2);

    head = deleteAtStart(head);
    head = deleteAtEnd(head);
    head = deleteRear(head);

    printLinkedList(head);

    // Free memory (optional cleanup)
    Node *temp;
    while (head) {
        temp = head->next;
        free(head);
        head = temp;
    }
    return 0;
}