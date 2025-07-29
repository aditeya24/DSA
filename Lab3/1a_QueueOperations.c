#include <stdio.h> 
#define MAX_SIZE 10

typedef struct {
	int arr[MAX_SIZE];
	int rear;
	int front;
} Queue;

int isFull(Queue *Q) {
	if(Q->rear==MAX_SIZE-1)
		return 1;
	else
		return 0;
}

int isEmpty(Queue *Q) {
	if(Q->front == -1 || Q->front > Q->rear)
		return 1;
	else
		return 0;
}

void ENQUEUE(Queue *Q,int item) {
	if(isFull(Q))
		printf("Queue overflow\n");
	else
	{
		if(Q->front==-1 && Q->rear==-1)
		{
			Q->front=0;
			Q->arr[++(Q->rear)]=item;
		}
		else
			Q->arr[++(Q->rear)]=item;
	}
}

void DEQUEUE(Queue *Q) {
	if(isEmpty(Q))
		printf("Queue underflow\n");
	else
	{
		int item=Q->arr[Q->front];
		printf("Dequeued: %d\n", item);

		if(Q->front==Q->rear)
		{
			Q->front=-1;
			Q->rear=-1;
		}
		else
		{
			Q->front=Q->front+1;
			
		}
	}
}

int main() {
	Queue Q;
	Q.front=-1;
	Q.rear=-1;
	int choice, item;
	while(1)
	{
		printf("\n1: ENQUEUE\n2: DEQUEUE\n0: Exit\n");
		printf("Enter choice[1,2,0]: ");
		scanf("%d", &choice);
		if(choice==0)
			break;
		else if(choice==1)
		{
			printf("Enter value to ENQUEUE: ");
			scanf("%d", &item);
			ENQUEUE(&Q, item);
		}
		else if(choice==2)
		{
			DEQUEUE(&Q);
		}
		else
		{
			printf("ERROR: Invalid choice\n");
		}
	}
	return 0;
}
