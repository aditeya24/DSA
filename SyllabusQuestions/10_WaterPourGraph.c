#include <stdio.h>
#include <stdlib.h>

#define MAX 11

typedef struct State {
    int a, b, c;
    struct State* parent;
} State;

typedef struct QueueNode {
    State *state;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

State* createState(int a, int b, int c, State *parent) {
    State* newState = (State*)malloc(sizeof(State));
    newState->a = a;
    newState->b = b;
    newState->c = c;
    newState->parent = parent;
    return newState;
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, State *state) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->state = state;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

State* dequeue(Queue *q) {
    if (q->front == NULL)
        return NULL;
    QueueNode *temp = q->front;
    State *state = temp->state;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return state;
}

void printPath(State *state) {
    if (state == NULL)
        return;
    printPath(state->parent);
    printf("(%d, %d, %d)\n", state->a, state->b, state->c);
}

void pour(State *curr, Queue *q, int visited[MAX][MAX][MAX]) {
    int A = curr->a, B = curr->b, C = curr->c;
    int maxA = 10, maxB = 7, maxC = 4;

    int pourAmt = (B + A > maxB) ? maxB - B : A;
    if (pourAmt > 0) {
        int na = A - pourAmt, nb = B + pourAmt, nc = C;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    pourAmt = (C + A > maxC) ? maxC - C : A;
    if (pourAmt > 0) {
        int na = A - pourAmt, nb = B, nc = C + pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    pourAmt = (A + B > maxA) ? maxA - A : B;
    if (pourAmt > 0) {
        int na = A + pourAmt, nb = B - pourAmt, nc = C;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    pourAmt = (C + B > maxC) ? maxC - C : B;
    if (pourAmt > 0) {
        int na = A, nb = B - pourAmt, nc = C + pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    pourAmt = (A + C > maxA) ? maxA - A : C;
    if (pourAmt > 0) {
        int na = A + pourAmt, nb = B, nc = C - pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    pourAmt = (B + C > maxB) ? maxB - B : C;
    if (pourAmt > 0) {
        int na = A, nb = B + pourAmt, nc = C - pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int visited[MAX][MAX][MAX] = {0};

    State *start = createState(0, 7, 4, NULL);
    enqueue(&q, start);
    visited[0][7][4] = 1;

    while (!isEmpty(&q)) {
        State *curr = dequeue(&q);

        if (curr->b == 2 || curr->c == 2) {
            printf("\nSolution path:\n");
            printPath(curr);
            return 0;
        }

        pour(curr, &q, visited);
    }

    printf("No solution found.\n");
    return 0;
}
