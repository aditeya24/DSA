#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coeff;
  int exp;
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
	printf("List: ");
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
	printf("Data deleted: %d\n", toDelete->data);
	free(toDelete);
}

void input(Node* head, int terms) {
  for (int i = 0; i < terms; i++) {
    Node *newNode = createNode();
    if (newNode == NULL) {
      printf("ERROR: Memory insufficient\n");
      return;
    }
  
    printf("Coefficient: ");
    scanf("%d", &)
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = head;
    head = newNode;
  }
  printf("\n");
}

int add(Node* head_A, Node* head_B, Node* head_C) {
  int index = 0, flag, i = 0;
  while (head_A->next != NULL && head_B->next != NULL) {
    
  }
}

int main() {
	int choice, item, terms;
	while (1) {
		printf("\n1: Enter Polynomial A\n2: Enter Polynomial 2\n3: Sum of A and B\n4: Product of A and B\n5: Diplay A\n6: Diplay B\n0: Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				return 0;
			case 1:
        printf("Enter no. of terms to insert: ");
				scanf("%d", &terms);
        input(head_A, terms);
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
