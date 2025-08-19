#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

int isFull() {
	return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
	return (front == -1);
}

void insertFront(int item) {
	if (isFull()) {
		printf("Deque overflow\n");
		return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	} else if (front==0) {
		front = MAX - 1;
	} else {
		front = front - 1;
	}
	deque[front] = item;
	printf("Inserted %d at front\n", item);
}

void insertRear(int item) {
	if (isFull()) {
		printf("Deque overflow\n");
		return;
	}
	if (rear == -1) {
		front = 0;
		rear = 0;
	} else if (rear == MAX - 1) {
		rear = 0;
	} else {
		rear = rear + 1;
	}
	deque[rear] = item;
	printf("Inserted %d at rear\n", item);
}

void deleteFront() {
	if (isEmpty()) {
		printf("Deque underflow\n");
		return;
	}
	int item = deque[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (front == MAX - 1) {
		front = 0;
	} else {
		front = front + 1;
	}
	printf("Deleted %d from front\n", item);
}

void deleteRear() {
	if (isEmpty()) {
		printf("Deque underflow\n");
		return;
	}
	int item = deque[rear];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (rear == 0) {
		rear = MAX - 1;
	} else {
		rear = rear - 1;
	}
	printf("Deleted %d from rear\n", item);
}

void display() {
	if (isEmpty()) {
		printf("Deque is empty\n");
		return;
	}
	printf("Deque: ");
	int i = front;
	while (1) {
		printf("%d ", deque[i]);
		if (i == rear)
			break;
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int main() {
	int choice, item;
	while (1) {
		printf("\n1: Input-Restricted Queue\n2: Output-Restricted Queue\n0: Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		} else if (choice == 1) {
			while (1) {
				printf("\n1: InsertRear\n2: DeleteFront\n3: DeleteRear\n4: Display\n0: Go Back\n");
				printf("Enter choice: ");
				scanf("%d", &choice);
				if (choice == 0) {
					break;
				} else if (choice == 1) {
					printf("Enter value to insert: ");
					scanf("%d", &item);
					insertRear(item);
					display();
				} else if (choice == 2) {
					deleteFront();
					display();
				} else if (choice == 3) {
					deleteRear();
					display();
				} else if (choice == 4) {
					display();
				} else {
					printf("ERROR: Invalid choice\n");
							
				}
			}
		} else if (choice == 2) {
			while (1) {
				printf("\n1: InsertFront\n2: InsertRear\n3: DeleteFront\n4: Display\n0: Go Back\n");
				printf("Enter choice: ");
				scanf("%d", &choice);
				if (choice == 0) {
					break;
				} else if (choice == 1) {
					printf("Enter value to insert: ");
					scanf("%d", &item);
					insertFront(item);
					display();
				} else if (choice == 2) {
					printf("Enter value to insert: ");
					scanf("%d", &item);
					insertRear(item);
					display();
				} else if (choice == 3) {
					deleteFront();
					display();
				} else if (choice == 4) {
					display();
				} else {
					printf("ERROR: Invalid choice\n");
							
				}
			}
		}
	}
	return 0;
}
