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
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
	Node *ptr = head;
	printf("List: ");
	do {
		printNode(ptr);
		ptr = ptr->next;
    } while (ptr != head);
	printf("NULL\n");
}

void insertFront (int data) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        newNode->next = head;
        ptr->next = newNode;
        head = newNode;
    }
	printf("Inserted %d\n", data);
}

void insertRear (int data) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;
	
	if (head == NULL) {
		head = newNode;
        newNode->next = head;
		return;
	}
	
	Node *ptr = head;
	while (ptr->next != head) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
    newNode->next = head;
	printf("Inserted %d\n", data);
}

void insertAtPosition (int data, int position) {
    if (position == 1) {
		insertFront(data);
		return;
	}
    Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->data = data;
	

	Node *curr = head;
	int count = 1;
    while (count < position - 1 && curr->next != head) {
        curr = curr->next;
        count++;
    }

	if (count != position -1) {
		printf("Position not found\n");
		free(newNode);
		return;
	}
	newNode->next = curr->next;
	curr->next = newNode;
	printf("Inserted %d\n", data);
}

void deleteFront () {
	Node *toDelete;
	if (head == NULL) {
		printf("List is already empty\n");
		return;
	}
    if (head->next == head) {
        printf("Data deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    toDelete = head;
	head = head->next;
    last->next = head;
	printf("Data deleted: %d\n", toDelete->data);
	free(toDelete);
}

void deleteRear () {
	Node *toDelete, *secondLastNode;
	if (head == NULL) {
		printf("List is already empty\n");
		return;
	}
    if (head->next == head) {
        printf("Data deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

	toDelete = head;
	secondLastNode = NULL;
	
	while (toDelete->next != head) {
		secondLastNode = toDelete;
		toDelete = toDelete->next;
	}
	secondLastNode->next = head;
    printf("Data deleted: %d\n", toDelete->data);
    free(toDelete);
}

void deleteAtPosition (int position) {
	int i;
	Node *toDelete, *prevNode;
	if (head == NULL) {
		printf("List is already empty\n");
	} else if (position == 1) {
		deleteFront();
	} else {
		toDelete = head;
		prevNode = head;
        int count = 1;
	    do {
            if (count == position) {
                break;
            }
            prevNode = toDelete;
            toDelete = toDelete->next;
            count++;
        } while (toDelete != head);

        if (count != position) {
            printf("ERROR: Position not found\n");
            return;
        }
		prevNode->next = toDelete->next;
		printf("Data deleted: %d\n", toDelete->data);
		free(toDelete);
	}
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
