#include <stdio.h>
#include <stdlib.h>
#define MAX 20 

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* headTree = NULL;

typedef struct Stack {
	struct Node* ptr;
	struct Stack* next;
} Stack;

Stack *headA = NULL;
Stack *headB = NULL;

char infix[MAX];

Node* createNode(int data) { 
        Node* newNode = (Node*)malloc(sizeof(Node)); 
        newNode->data = data; 
        newNode->left = NULL; 
        newNode->right = NULL; 
        return newNode; 
}

int precedence(char c) {
	switch (c) {
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
		}
	return 0;
}

void push(int data) {
	Node *newNode = createNode(data);
	if (newNode == NULL) {
		printf("ERROR: Memory insufficient\n");
		return;
	}
	newNode->next = head;
	head = newNode;
}

Node* pop() {
	Node *toDelete;
	if (head == NULL) {
		printf("Stack is already empty\n");
		return;
	}
	toDelete = head;
	head = head->next;
	printf("Popped: %d\n", toDelete->data);
	return toDelete;
	free(toDelete);
}

char peek() {
	if (head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	return headS->ptr->data;
}

void createExpressionTree (char *str) {
	top = -1;
	int i = 0, j = 0;
	char item;
	while (curr != NULL) {
		item = curr->data	Node *toDelete;
	if (head == NULL) {
		printf("Stack is already empty\n");
		return;
	}
	toDelete = head;
	head = head->next;
	printf("Popped: %d\n", toDelete->data);
	free(toDelete);;
		if ( (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9') ) {
			push(
}

void createExpressionTree(char s[]) {
	top = -1;
	int i = 0, j = 0;
	char item;
	while (s[i] != '\0') {
		item = s[i];
		if ( (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9') ) {
			push(s[i], headA);
		} else if (item == ')') {
			while (peek() != '(') {
				postfix[j++] = pop();
			}
			pop();
		} else if (item == '(') {
			push(item);
		} else {
			while (precedence(peek()) >= precedence(item) || (precedence(peek()) == precedence(item) && item != '^')) {
				postfix[j++] = pop();
			}
			push(item);
		}
		i++;
	}

	while (peek() != '#') {
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	
	return postfix;
}

 

int main() {
	printf("Enter Infix expression: ");
	scanf("%s", infix);
	const char* postfix = infixToPostfix(infix);
	
	return 0;	
}
