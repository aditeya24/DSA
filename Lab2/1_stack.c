#include <stdio.h>
#define MAX 10

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
  printf("Inserted: %d\n", item);
}

void pop() {
  int item;
  if (empty()) {
    printf("Stack underflow\n");
    return;	
  }
  item = a[top--];
  printf("Removed: %d\n", item);
}

void peek() {
  if (empty()) {
    printf("Stack is empty\n");
    return;
  }
  printf("%d\n", a[top]);
}


int main() {
  int choice, item;
  while(1) {
    printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n0: Exit\n");
    printf("Enter choice[1,2,3,4,0]: ");
    scanf("%d", &choice);
    if (choice==0) {
      break;
    } else if (choice==1) {
      printf("Enter value to push: ");
      scanf("%d", &item);
      push(item);
      display();
    } else if (choice==2) {
      pop();
      display();
    } else if (choice==3) {
      peek();
    } else if (choice==4) {
      display();
    } else {
      printf("ERROR: Invalid choice\n");
    }
  }
  return 0;
}
