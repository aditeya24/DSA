#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode () {
	Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
    }
	return newNode;
}

void printNode(Node *ptr) {
	printf("%d", ptr->data);
}

void traverse () {
	Node *ptr = head;
	printf("List: ");
	while (ptr != NULL) {
		printNode(ptr);
    printf("->");
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void reverseTraverse () {
	Node *ptr = tail;
	printf("List: ");
	while (ptr != NULL) {
		printNode(ptr);
    printf("<-");
		ptr = ptr->prev;
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
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
	head = newNode;
	printf("Inserted %d\n", data);
}

void insertRear (int data) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
	printf("Inserted %d\n", data);
}

void insertAtPosition (int data, int position) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;
	if (position == 1) {
		insertFront(data);
		return;
	}

	Node *curr = head;
	int count = 2;
	while (curr != NULL) {
		if (count == position) {
			break;
		}
		count++;
		curr = curr->next;
	}
	
	if (curr == NULL) {
		printf("Position not found\n");
		free(newNode);
		return;
	}
	newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = newNode;
    } else {
        tail = newNode;
    }
	curr->next = newNode;
	printf("Inserted %d\n", data);
}

void deleteFront () {
	Node *toDelete;
	if (head == NULL) {
		printf("List is already empty\n");
		return;
	}
	toDelete = head;
	head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
	printf("Data deleted: %d\n", toDelete->data);
	free(toDelete);
}

void deleteRear () {
	Node *toDelete;
	if (head == NULL) {
		printf("List is already empty\n");
		return;
	}
	toDelete = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
	printf("Data deleted: %d\n", toDelete->data);
	free(toDelete);	
}

void deleteAtPosition (int position) {
	Node *toDelete;
	if (head == NULL) {
		printf("List empty");
	} else if (position == 1) {
		deleteFront();
    return;
	}

    toDelete = head;
    for (int i = 2; i <= position; i++) {
        toDelete = toDelete->next;
        if (toDelete == NULL) {
            printf("ERROR: Position not found\n");
            return;
        }
    }
    if (toDelete->prev != NULL) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }
    if (toDelete->next != NULL) {
        toDelete->next->prev = toDelete->prev;
    } else {
        tail = toDelete->prev;
    }
    printf("Data deleted: %d\n", toDelete->data);
    free(toDelete);
}

int main() {
	int choice, item, position;
	while (1) {
		printf("\n1: Insert Front\n2: Insert Rear\n3: Insert at Position\n4: Delete Front\n5: Delete Rear\n6: Delete At Position\n7: Display\n0: Exit\nEnter choice: ");
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
				printf("Enter element: ");
				scanf("%d", &item);
				insertRear(item);
				traverse();
				break;
			case 3:
				printf("Enter element: ");
				scanf("%d", &item);
                printf("Enter position: ");
				scanf("%d", &position);
				insertAtPosition(item, position);
				traverse();
				break;
			case 4:
				deleteFront();
				traverse();
				break;
			case 5:
				deleteRear();
				traverse();
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d", &position);
				deleteAtPosition(position);
				traverse();
				break;
			case 7:
				traverse();
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}	
