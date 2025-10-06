#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;

Node *createNode() {
	Node *newNode = (Node*)malloc(sizeof(Node));
	return newNode;
}

void printNode(Node *ptr) {
	printf("%d->", ptr->data);
}

void traverse() {
	Node *ptr = head;
	printf("Queue: ");
	while (ptr != NULL) {
		printNode(ptr);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void insertFront(int data) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	printf("Inserted %d\n", data);
}

void deleteRear() {
	Node *toDelete, *secondLastNode;
	if (head == NULL) {
		printf("Queue is already empty\n");
		return;
	}

	toDelete = head;
	secondLastNode = head;
	
	while (toDelete->next != NULL) {
		secondLastNode = toDelete;
		toDelete = toDelete->next;
	}
	if (toDelete == head) {
		head = NULL;
	} else {
		secondLastNode->next = NULL;
	}
	printf("Data deleted: %d\n", toDelete->data);
	free(toDelete);	
}

int main() {
	int choice, item, position;
	while (1) {
		printf("\n1: Enqueue\n2: Dequeue\n3: Display\n0: Exit\nEnter choice: ");
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
				deleteRear();
				traverse();
				break;
			case 3:
				traverse();
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}
