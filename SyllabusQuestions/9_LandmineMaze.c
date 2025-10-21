#include <stdio.h>
#include <stdlib.h>
#define ROWMAX 20
#define COLMAX 20

typedef struct {
    int row;
    int col;
} Cell;

Cell* queue[ROWMAX * COLMAX];
int front = -1;
int rear = -1;

Cell* createNode(int r, int c) {
    Cell* newNode = (Cell *)malloc(sizeof(Cell));
    newNode->row = r;
    newNode->col = c;
    return newNode;
}

int isFull() {
    return rear == ROWMAX * COLMAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int r, int c) {
    if (isFull()) {
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
    }
    queue[++rear] = createNode(r, c);
}

Cell* dequeue() {
    if (isEmpty()) {
        return NULL;
    }
    Cell* item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return item;
}

void allShortestDistances(int rows, int cols, char maze[rows][cols], int dist[rows][cols]) {
    int move_r[] = {1, -1, 0, 0};
    int move_c[] = {0, 0, -1, 1};
    Cell* cell;
    int r, c, nr, nc;

    while (!isEmpty()) {
        cell = dequeue();
        r = cell->row;
        c = cell->col;
        for (int i = 0; i < 4; i++) {
            nr = r + move_r[i];
            nc = c + move_c[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && dist[nr][nc] == -1 && maze[nr][nc] != 'W') {
                dist[nr][nc] = dist[r][c] + 1;
                enqueue(nr, nc);
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter size of maze [upto 20x20]:\nRows: ");
    scanf("%d", &rows);
    printf("Columns: ");
    scanf("%d", &cols);

    char maze[rows][cols];
    int dist[rows][cols];
    printf("Enter maze layout row-wise [W = wall, L = landmine, O = open]:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <cols; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'L') {
                dist[i][j] = 0;
                enqueue(i, j);
            } else {
                dist[i][j] = -1;
            }
        }
    }

    allShortestDistances(rows, cols, maze, dist);
    printf("Distance:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dist[i][j] == -1) {
                printf("W ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
