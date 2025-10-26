#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, const char* word) {
    Node* newNode = createNode(word);
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void findandreplace(Node* head, const char* target, const char* replacement) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->word, target) == 0) {
            strcpy(temp->word, replacement);
        }
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char word[50], target[50], replacement[50];
    Node* head = NULL;
    printf("Enter a sentence (press Enter to finish):\n");
    while (scanf("%s", word) == 1) {
        head = insertEnd(head, word);
        char ch = getchar();
        if (ch == '\n') break; 
    }
    printf("\nOriginal sentence:\n");
    display(head);
    printf("\nEnter the word to find: ");
    scanf("%s", target);
    printf("Enter the word to replace: ");
    scanf("%s", replacement);
    findandreplace(head, target, replacement);
    printf("\nModified sentence:\n");
    display(head);
    freeList(head);
    return 0;
}
