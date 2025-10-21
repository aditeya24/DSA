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
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertion(Node** root, char word[], char meaning[]) {
    if (*root == NULL) {
        return createNode(word, meaning);
    } else if (strcmp(word, (*root)->word) < 0) {
        (*root)->left = insertion(&((*root)->left), word, meaning);
    } else if (strcmp(word, (*root)->word) > 0) {
        (*root)->right = insertion(&((*root)->right), word, meaning);
    } else {
        strcpy((*root)->meaning, meaning);
    }
    return *root;
}

Node* search(Node* root, char word[]) {
    if (root == NULL) {
        printf("Word not found\n");
        return NULL;
    } else if (strcmp(word, root->word) < 0) {
        return search(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        return search(root->right, word);
    } else {
        return root;
    }
}

void display(Node* root) {
    if (root != NULL) {
        printf("Word: %s\nMeaning: %s\n\n", root->word, root->meaning);
    }
}

void InOrderTraversal(Node* root) {
    if (root != NULL) {
        InOrderTraversal(root->left);
        display(root);
        InOrderTraversal(root->right);
    }
}

int main() {
    int choice;
    char word[MAXWORD], meaning[MAXDEFITION];
    Node *temp;

    while (1) {
        strcpy(word, "");
        strcpy(meaning, "");
        temp = NULL;
        printf("\n1: Add a word\n2: Add/Update meaning\n3: Display meaning\n4: Display dictionary\n0: Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                return 0;
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                headTree = insertion(&headTree, word, "");
                display(search(headTree, word));
                break;
            case 2:
                printf("Enter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf("%s", meaning);
                headTree = insertion(&headTree, word, meaning);
                display(search(headTree, word));
                break;
            case 3:
                printf("Enter word: ");
                scanf("%s", word);
                display(search(headTree, word));
                break;
            case 4:
                InOrderTraversal(headTree);
                break;
            default:
                printf("ERROR: Invalid choice\n");
        }
    }
}
