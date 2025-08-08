#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
	return rear == MAX - 1;
}

int isEmpty() {
	return front == -1 || front > rear;
}

void enqueue(int item) {
	if (isFull()) {
		printf("Queue overflow\n");
		return;
	}
	if (front == -1 && rear == -1) {
		front = 0;
	}
	queue[++rear] = item;
	printf("Enqueued: %d\n", item);
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
		front+=1;
	}
	printf("Dequeued: %d\n", item);
}

void display() {
	if (isEmpty()) {
		printf("Queue is Empty\n");
		return;
	}
	printf("Queue: ");
	int i = front;
	while (1) {
		printf("%d ", queue[i]);
		if (i == rear)
			break;
		i = i + 1;
	}
	printf("\n");
}

void maxValue() {
	int i = front;
	int index, max=queue[front];
	while (1) {
		if (queue[i]>max) {
			index = i;
			max = queue[i];
		}
		if (i == rear) {
			break;
		}
		i++;
	}
	printf("Max Value: %d\nIndex: %d\n", max, index);
}

int main() {
	int choice, item;
	while (1) {
		printf("\n1: Enqueue\n2: Dequeue\n3: Max\n4: Display\n0: Exit\n");
		printf("Enter choice[1,2,3,4,0]: ");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		} else if (choice == 1) {
			printf("Enter value to enqueue: ");
			scanf("%d", &item);
			enqueue(item);
			display();
		} else if (choice == 2) {
			dequeue();
			display();
		} else if (choice == 3) {
			maxValue();
			display();
		} else if (choice == 4) {
			display();
		} else {
			printf("ERROR: Invalid choice\n");
		}
	}
	return 0;
}
