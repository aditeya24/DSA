#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;

Node *createNode () {
	Node *newNode = (Node*)malloc(sizeof(Node));
	return newNode;
}

void printNode(Node *ptr) {
	printf("%d->", ptr->data);
}

void traverse () {
	Node *ptr = head;
	printf("Stack: ");
	while (ptr != NULL) {
		printNode(ptr);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void insertFront (int data) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;
	newNode->next = head;
	head = newNode;
    printf("Pushed: %d\n", data);
}

void deleteFront () {
	Node *toDelete;
	if (head == NULL) {
		printf("Stack is already empty\n");
		return;
	}
	toDelete = head;
	head = head->next;
	printf("Popped: %d\n", toDelete->data);
	free(toDelete);
}

void peek () {
	if (head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	printf("Peek: %d\n", head->data);
}


int main () {
	int choice, item, position;
	while (1) {
    printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n0: Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				return 0;
			case 1:
				printf("Enter element: ");
				scanf("%d", &item);
				insertFront(item);
				traverse();
				break;
			case 2:
                deleteFront();
				traverse();
				break;
            case 3:
                peek();
                break;
			case 4:
				traverse();
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}
