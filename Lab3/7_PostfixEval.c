#include <stdio.h>
#define MAX 20

char postfix[MAX];
int a[MAX];
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

void push(int item) {
  if (full()) {
    printf("Stack overflow\n");
    return;
  }
  a[++top]=item;
}

int pop() {
  int item;
  if (empty()) {
    return 0;
  }
  item = a[top--];
  return item;
}

int peek() {
  if (empty()) {
    return 0;
  }
  return a[top];
}

int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int doOperation(int x, int y, char item) {
  switch (item) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/': {
      if (y == 0) {
        printf("ERROR: Division by zero\n");
        return 0;
      }
      return x / y;
    }
    case '^': {
      int z = 1;
      for (int i = 0; i < y; i++) { z *= x; }
      return z;
    }
    default:
      return 0;
  }
}

int evaluate(char s[]) {
  int i = 0;
  char item;
  while (s[i] != '\0') {
    item = s[i];
    if (item >= '0' && item <= '9') {
      push(item - '0');
    } else if (isOperator(item)) {
      int y = pop();
      int x = pop();
      push(doOperation(x, y, item));
    }
    i++;
  }
  return pop();
}

int main() {
  printf("Enter Postfix expression: ");
  scanf("%s", postfix);
  int result = evaluate(postfix);
  printf("Result: %d\n", result);
  return 0;
}
