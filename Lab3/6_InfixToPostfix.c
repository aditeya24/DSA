#include <stdio.h>
#define MAX 20 

int j = 0;
char infix[MAX];
char postfix[MAX];
char a[MAX];
int top = -1;

int full() {
  return top == MAX-1;
}

int empty() {
  return top == -1;
}

void display() {
  if (empty()) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}

void push(char item) {
  if (full()) {
    printf("Stack overflow\n");
    return;
  }
  a[++top]=item;
}

char pop() {
  char item;
  if (!empty()) {
    item = a[top--];
    return item;
  }
}

char peek() {
  if (!empty()) {
    return a[top];
  }
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

void infixToPostfix(char s[]) {
  top = -1;
  int i = 0, j = 0;
  char item;
  push('#');
  while (s[i] != '\0') {
    item = s[i];
    if ( (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9') ) {
      postfix[j++] = s[i];
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

  printf("Postfix: %s\n", postfix);
}

int main() {
  printf("Enter Infix expression: ");
  scanf("%s", infix);
  infixToPostfix(infix);
  return 0;
}
