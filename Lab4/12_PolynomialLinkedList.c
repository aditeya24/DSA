#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coeff;
  int exp;
	struct Node *next;
} Node;

Node *headA = NULL;
Node *headB = NULL;
Node *headC = NULL;
Node *headD = NULL;

Node *createNode () {
	Node *newNode = (Node*)malloc(sizeof(Node));
	return newNode;
}

void insertFront (Node **head, int coeff, int exp) {
	Node *newNode = createNode();
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = *head;
	*head = newNode;
}

void input(Node **head, int terms) {
  int coeff, exp;
  for (int i = 0; i < terms; i++) {
    Node *newNode = createNode();
    if (newNode == NULL) {
      printf("ERROR: Memory insufficient\n");
      return;
    }

    printf("Coefficient: ");
    scanf("%d", &coeff);
    printf("Exponent: ");
    scanf("%d", &exp);
    insertFront(head, coeff, exp);
  }
}

void clearList(Node **head) {
  Node *curr = *head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
  *head = NULL;
}

void add(Node *head_A, Node *head_B, Node **head_C) {
  int sum = 0;
  Node *curr_A = head_A;
  Node *curr_B = head_B;

  if (curr_A == NULL && curr_B == NULL) {
    return;
  }

  while (curr_A != NULL && curr_B != NULL) {
    if (curr_A->exp == curr_B->exp) {
      sum = curr_A->coeff + curr_B->coeff;
      insertFront(head_C, sum, curr_A->exp);
      curr_A = curr_A->next;
      curr_B = curr_B->next;
    } else if (curr_A->exp > curr_B->exp) {
      insertFront(head_C, curr_B->coeff, curr_B->exp);
      curr_B = curr_B->next;
    } else if (curr_A->exp < curr_B->exp) {
      insertFront(head_C, curr_A->coeff, curr_A->exp);
      curr_A = curr_A->next;
    }
  }

  if (curr_A != NULL) {
    while (curr_A != NULL) {
      insertFront(head_C, curr_A->coeff, curr_A->exp);
      curr_A = curr_A->next;
    }
  }

  if (curr_B != NULL) {
    while (curr_B != NULL) {
      insertFront(head_C, curr_B->coeff, curr_B->exp);
      curr_B = curr_B->next;
    }
  }
}

void product(Node *head_A, Node *head_B, Node **head_D) {
  
}

void printNode(Node *n) {
  if (n->coeff == 0) {
    return;
  }

  if (n->exp == 0) {
    printf("%d ", n->coeff);
    return;
  }
  
  if (n->coeff == 1) {
    printf("x^%d ", n->exp);
    return;
  }
	printf("%dx^%d ", n->coeff, n->exp);
}

void display(Node *head) {
  Node* curr = head;
  if (curr == NULL) {
    printf("0\n");
    return;
  }

  printNode(curr);
  curr = curr->next;

  while (curr != NULL) {
    printf("+ ");
		printNode(curr);
		curr = curr->next;
	}
  printf("\n");
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
        printf("Enter no. of terms: ");
				scanf("%d", &terms);
        clearList(headA);
        input(&headA, terms);
        printf("Polynomial A: ");
        display(headA);
				break;
			case 2:
        printf("Enter no. of terms: ");
				scanf("%d", &terms);
        clearList(headB);
        input(&headB, terms);
        printf("Polynomial B: ");
        display(headB);
				break;
			case 3:
        clearList(&headC);
        add(headA, headB, &headC);
        printf("Polynomial C: ");
        display(headC);
				break;
			case 4:
				break;
			case 5:
        printf("Polynomial A: ");
        display(headA);
				break;
			case 6:
        printf("Polynomial B: ");
        display(headB);
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}
