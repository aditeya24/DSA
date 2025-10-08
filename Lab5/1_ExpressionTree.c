#include <stdio.h>
#include <stdlib.h>
#define MAX 20 

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
} Node;

Node *headTree = NULL;

typedef struct Stack {
	struct Node* ptr;
	struct Stack* next;
} Stack;

Stack *operandStack = NULL;
Stack *operatorStack = NULL;

Node* createNode(int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
}

Stack* createStackNode(Node *ptr) { 
    Stack* newNode = (Stack*)malloc(sizeof(Stack)); 
    newNode->ptr = ptr; 
    newNode->next = NULL; 
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

void push(Node *newNode, Stack **head) {
    Stack *newStackNode = createStackNode(newNode);
	newStackNode->next = *head;
	*head = newStackNode;
}

Node* pop(Stack **head) {
	if (*head == NULL) {
		printf("Stack is already empty\n");
		return NULL;
	}
	Stack *toDelete = *head;
	Node *node = toDelete->ptr;
	*head = toDelete->next;
	free(toDelete);
    return node;
}

char peekValue(Stack *head) {
    if (head == NULL) {
        return '\0';
    }
	return head->ptr->data;
}

Stack* peekStack(Stack *head) {
	if (head == NULL) {
		return NULL;
	}
	return head;
}

void createExpressionTree(char s[]) {
	int i = 0, j = 0;
	char item;
    Node *temp;
	while (s[i] != '\0') {
		item = s[i];
		if ( (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9') ) {
			push(createNode(item), &operandStack);
		} else if (item == ')') {
			while (peekValue(operatorStack) != '\0' && peekValue(operatorStack) != '(') {
				temp = pop(&operatorStack);
                temp->right = pop(&operandStack);
                temp->left = pop(&operandStack);
                push(temp, &operandStack);
			}
			pop(&operatorStack);
		} else if (item == '(') {
			push(createNode(item), &operatorStack);
		} else {
			while (peekValue(operatorStack) != '\0' && (precedence(peekValue(operatorStack)) > precedence(item) || (precedence(peekValue(operatorStack)) == precedence(item) && item != '^'))) {
				temp = pop(&operatorStack);
                temp->right = pop(&operandStack);
                temp->left = pop(&operandStack);
                push(temp, &operandStack);

			}
			push(createNode(item), &operatorStack);
		}
		i++;
	}

	while (operatorStack != NULL) {
        temp = pop(&operatorStack);
        temp->right = pop(&operandStack);
        temp->left = pop(&operandStack);
        push(temp, &operandStack);
    }
    headTree = pop(&operandStack);
}

void Preorder(Node *ptr) {
    if (ptr != NULL) {
        printf("%c", ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}

void Inorder(Node *ptr) {
    if (ptr != NULL) {
        Inorder(ptr->left);
        printf("%c", ptr->data);
        Inorder(ptr->right);
    }
}

void Postorder(Node *ptr) {
    if (ptr != NULL) {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf("%c", ptr->data);
    }
}

int main() {
    char infix[MAX];
	printf("Enter Infix expression: ");
	scanf("%s", infix);
    int choice;

    createExpressionTree(infix);
    while (1) {
        printf("\n1: Display Prefix Expression\n2: Display Infix Expression\n3: Display Postfix Expression\n0: Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
               return 0;
            case 1:
                printf("Preorder Expression: ");
                Preorder(headTree);
                printf("\n");
                break;
            case 2:
                printf("Inorder Expression: ");
                Inorder(headTree);
                printf("\n");
                break;
            case 3:
                printf("Postorder Expression: ");
                Postorder(headTree);
                printf("\n");
                break;
            default:
                printf("ERROR: Invalid choice\n");
                break;
        }
    }
}
