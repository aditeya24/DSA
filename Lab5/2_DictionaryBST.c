#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define MAXDEFITION 300

typedef struct Node {
	char word[MAXWORD];
	char meaning[MAXDEFITION];
	struct Node* left;
	struct Node* right;
} Node;

Node *headTree = NULL;

Node* createNode(char word[], char meaning[]) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->word = word; 
    newNode->meaning = meaning; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
}

Node** insertion(Node** root, char word[]) {
    if (*root == NULL) {
        return createNode(word);
    } else if (strcmp(word, (*root)->data) < 0) {
        (*root)->left = insertion(&((*root)->left), word);
    } else {
        (*root)->right = insertion(&((*root)->right), word);
    }
    return root;
}


