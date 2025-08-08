#include <stdio.h> 
#define MAX 10

typedef struct {
	int arr[MAX];
	int rear;
	int front;
} Queue;

int isFull(Queue *Q) {
  return Q->rear == MAX - 1;
}

int isEmpty(Queue *Q) {
	return (Q->front == -1 || Q->front > Q->rear);
}

void enqueue(Queue *Q,int item) {
	if (isFull(Q)) {
    printf("Queue overflow\n");
  } else {
    if(Q->front==-1 && Q->rear==-1) {
			Q->front=0;
			Q->arr[++(Q->rear)]=item;
		} else {
      Q->arr[++(Q->rear)]=item;
    }
	}
}

void dequeue(Queue *Q) {
	if (isEmpty(Q)) {
    printf("Queue underflow\n");
  }	else {
		int item = Q->arr[Q->front];
		printf("Dequeued: %d\n", item);

		if (Q->front==Q->rear) {
			Q->front=-1;
			Q->rear=-1;
		} else {
			Q->front=Q->front+1;
		}
	}
}

void display(Queue *Q) {
  if(isEmpty(Q)) {
    printf("Queue is Empty\n");
    return;
  }
  printf("Queue: ");
  int i = Q->front;
  while (1) {
    printf("%d ", Q->arr[i]);
    if (i == Q->rear)
      break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main() {
  Queue Q;
  Q.front = -1;
  Q.rear = -1;
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
			enqueue(&Q, item);
			display(&Q);
		} else if (choice == 2) {
			dequeue(&Q);
			display(&Q);
		} else if (choice == 3) {
			display(&Q);
		} else {
			printf("ERROR: Invalid choice\n");
		}	
	}
	return 0;
}
