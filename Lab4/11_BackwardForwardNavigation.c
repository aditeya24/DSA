#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
  struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *curr = NULL;

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

void display() {
	Node *ptr = head;
	printf("List: ");
	while (ptr != NULL) {
		printNode(ptr);
    printf("->");
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void reverseTraverse() {
	Node *ptr = tail;
	printf("List: ");
	while (ptr != NULL) {
		printNode(ptr);
    printf("<-");
		ptr = ptr->prev;
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
  newNode->prev = NULL;
  if (head != NULL) {
    head->prev = newNode;
  } else {
    tail = newNode;
  }
	head = newNode;
	printf("Inserted %d\n", data);
}

void insertRear(int data) {
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

void insertAtPosition(int data, int position) {
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

void deleteFront() {
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

void deleteRear() {
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
		printf("\n1: Home\n2: About\n3: Events\n4: Team\n5: Contact\n6: Previous Page\n");
	  if (curr != head) {
      printf("7: Next page\n");
    }
    printf("0: Exit\nEnter choice: ");
    scanf("%d", &choice);
		switch (choice) {
			case 0:
				return 0;
			case 1:
        insertFront(1);
        break;
			case 2:
        insertFront(2);
				break;
			case 3:
        insertFront(3);
				break;
			case 4:
        insertFront(4);
				break;
			case 5:
        insertFront(5);
				break;
			case 6:
        previousPage();
				break;
			case 7:
        nextPage();
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}
