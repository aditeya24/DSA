#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
	return (rear + 1) % MAX == front;
}

int isEmpty() {
	return front == -1;
}

void enqueue(int item) {
	if (isFull()) {
		printf("Queue overflow\n");
		return;
	}
	if (front == -1) {
		front = 0;
	}
	rear = (rear + 1) % MAX;
	queue[rear] = item;
	printf("Enqueued %d\n",item);
}

void dequeue() {
	if (isEmpty()) {
		printf("Queue underflow\n");
		return;
	}
	int item = queue[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else {
		front = (front + 1) % MAX;
	}
	printf("Dequeued %d\n", item);
}

void display() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue: ");
	int i = front;
	while (1) {
		printf("%d ", queue[i]);
		if(i == rear)
			break;
		i = (i +1) % MAX;
	}
	printf("\n");
}

int main() {
	int choice, item;
	while (1) {
		printf("\n1: Enqueue\n2: Dequeue\n3: Display\n0: Exit\n");
		printf("Enter choice[1,2,3,0]: ");
		scanf("%d", &choice);
		if (choice==0) {
			break;
		} else if (choice == 1) {
			printf("Enter value to insert: ");
			scanf("%d", &item);
			enqueue(item);
			display();
		} else if (choice == 2) {
			dequeue();
			display();
		} else if (choice == 3) {
			display();
		} else {
			printf("ERROR: Invalid choice\n");
		}	
	}
	return 0;
}
