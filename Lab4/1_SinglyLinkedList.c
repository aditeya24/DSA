#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head = NULL;

Node *createNode () {
	Node *new = (Node*)malloc(sizeof(Node));
	return new;
}

void returnNode(Node *ptr) {
	printf("%d\n", ptr->data);
}

void traverse () {
	Node *ptr = head;
	while (ptr != NULL) {
		returnNode(ptr);
		ptr = ptr->next;
	}
}

void insertFront (int data) {
	Node *new = createNode();
	if (new == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	new->data = data;
	new->next = head;
	head = new;
}

void insertRear (int data) {
	Node *new = createNode();
	if (new == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	Node *ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	new->data = data;
	ptr->next = new;
}

void insertAtPosition (int data, int item) {
	Node *new = createNode();
	if (new == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	Node *ptr = head;
	while (ptr->data != item && ptr->next != NULL) {
		ptr = ptr->next;
	}
	if (ptr->next == NULL) {
		printf("Item not available");
		return;
	}
	new->data = data;
	new->next = ptr->next;
	ptr->next = new;
}

void deleteFront () {
	Node *ptr = head;
	if (head == NULL) {
		printf("List is empty, no deletion\n");
		return;
	}
	Node *temp = ptr->next;	
	head = temp;
	returnNode(ptr);
	free(ptr);
}

void deleteRear () {
	Node *ptr = head;
	if (head == NULL) {
		printf("List is empty, no deletion\n");
		return;
	}
	Node *temp = NULL; 
	while (ptr->next != NULL) {
		temp = ptr;
		ptr = ptr->next;
	}
	temp->next = NULL;
	returnNode(ptr);
	free(ptr);
}

void deleteAtPosition (int item) {
	Node *ptr = head;
	Node *temp = NULL;
	while (ptr != NULL) {
		if (ptr->data != item) {
			temp = ptr;
			ptr = ptr->next;
		} else {
			temp->next = ptr->next;
			int item = ptr->data;
			returnNode(ptr);
			free(ptr);
		}
	}
	if (ptr == NULL) {
		printf("Node with item does not exist\n");
	}
}

int main() {
	insertFront(10);
	insertFront(20);
	insertRear(5);
	insertAtPosition(15, 10);
	traverse();
	deleteFront();
	traverse();
	deleteRear();
	traverse();
	deleteAtPosition(15);
	traverse();
	return 0;
}	
