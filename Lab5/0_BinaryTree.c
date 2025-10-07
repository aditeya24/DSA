#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int data;
        struct Node *left;
        struct Node *right;
} Node;

Node* createNode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
}

void insert(Node** root, int data) {
        Node* newNode = createNode(data);
}
