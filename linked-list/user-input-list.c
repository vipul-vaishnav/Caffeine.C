#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

int sumOfNodes(Node *head) {
    if (head == NULL) return 0;
    return head->val + sumOfNodes(head->next);
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void printListRecursive(Node *head) {
    if (head == NULL) {
        printf("NULL\n\n");
        return;
    }
    printf("%d->", head->val);
    printListRecursive(head->next);
}

void printListRecursiveReverse(Node *head) {
    if (head == NULL) {
        return;
    }
    printListRecursiveReverse(head->next);
    printf("%d ", head->val);
}

int lengthOfList(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* insertAtBeginning(Node *head) {
    printf("Inserting node at beginning\nEnter node value: ");
    int value;
    scanf("%d", &value);

    Node *temp = malloc(sizeof(Node));
    temp->val = value;
    temp->next = head;
    return temp;
}

Node* insertAtEnd(Node *head) {
    printf("Inserting node at end\nEnter node value: ");
    int value;
    scanf("%d", &value);

    Node *temp2 = malloc(sizeof(Node));
    temp2->val = value;
    temp2->next = NULL;

    if (head == NULL) return temp2;

    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = temp2;
    return head;
}

Node* reverseList(Node *head) {
    Node *prev = NULL, *curr = head;
    while (curr != NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("\n\nDONE!!\n\n");
    return prev;
}

// Node* reverseListRecursively(Node *head, Node *prev) {
//     if (head == NULL) return head;
//     if (head->next == NULL) {
//         head->next = prev;
//         return head;
//     }
//     Node *newHead = reverseListRecursively(head->next, head);
//     head->next = prev;
//     return newHead;
// }

Node* reverseListRecursively(Node *head, Node *prev) {
    if (head == NULL) return prev; // <-- return prev (new head)
    Node *next = head->next;
    head->next = prev;
    return reverseListRecursively(next, head);
}


int main(void) {
    printf("Start entering values for the node, enter -1 to stop!\n\n");

    Node *head = NULL, *tail = NULL;

    while (1) {
        int input;
        printf("Enter node val or -1 to stop: ");
        scanf("%d", &input);
        if (input == -1) break;

        Node *tempNode = malloc(sizeof(Node));
        tempNode->val = input;
        tempNode->next = NULL;

        if (head == NULL) {
            head = tail = tempNode;
        } else {
            tail->next = tempNode;
            tail = tempNode;
        }
    }

    printList(head);
    printf("Length: %d\n\n", lengthOfList(head));

    head = insertAtBeginning(head);
    head = insertAtEnd(head);

    printListRecursive(head);
    printf("\n");
    printListRecursiveReverse(head);
    printf("\n");

    head = reverseList(head);
    head = reverseListRecursively(head, NULL);

    printListRecursive(head);
    printf("\n");
    printListRecursiveReverse(head);
    printf("\n");

    // Free memory
    Node *curr = head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}
