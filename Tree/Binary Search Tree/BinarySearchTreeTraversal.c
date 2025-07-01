#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree() {
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node* root = createNode(value);
    printf("Enter left child of %d:\n", value);
    root->left = buildTree();
    printf("Enter right child of %d:\n", value);
    root->right = buildTree();

    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Build the binary tree:\n");
    root = buildTree();

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}