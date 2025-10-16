#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
} BinaryTreeNode;

BinaryTreeNode* createTreeNode(int val) {
    BinaryTreeNode *root = malloc(sizeof(BinaryTreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void freeTree(BinaryTreeNode *root) {
    if (root == NULL) return;

    BinaryTreeNode *temp = root;

    if (temp->left != NULL) {
        freeTree(temp->left);
    }
    if (temp->right != NULL) {
        freeTree(temp->right);
    }

    freeTree(temp);
}

void printTree(BinaryTreeNode *root) {
    if (root == NULL) return;

    //inorder

    printTree(root->left);
    printf("%d  ", root->val);
    printTree(root->right);
}

int heightOfTree(BinaryTreeNode *root) {
    if (root == NULL) return 0;

    int a = 0, b = 0, ans;

    if (root->left == NULL && root->right == NULL) return 0;
    a = heightOfTree(root->left);
    b = heightOfTree(root->right);

    ans = MAX(a, b) + 1;
    return ans;
}

int main(void){
    BinaryTreeNode *root = createTreeNode(10);

    root->left = createTreeNode(20);
    root->right = createTreeNode(30);

    root->left->left = createTreeNode(40);
    root->left->right = createTreeNode(50);
    root->right->left = createTreeNode(60);

    printf("\n");
    printTree(root);
    printf("\n");
    printf("HEIGHT: %d\n", heightOfTree(root));

    freeTree(root);

    return 0;
}
