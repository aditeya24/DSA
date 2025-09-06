#include <stdio.h>
#define MAX 101

typedef struct {
  int col;
  int row;
  int val;
} Matrix;

Matrix a[MAX];

void input() {
  int row, col;
  printf("Enter number of rows: ");
  scanf("%d", &row);
  printf("Enter number of columns: ");
  scanf("%d", &col);
  
  int mat[row][col];
  for (int i = 0; i < row; i++) {
    printf("Enter elements in row %d:\n", i);
    for (int j = 0; j < col; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
}

Matrix convert() {

}

void displayMatrix(int row, int col, int mat[row][col]) {
  printf("Matrix %c: ", ch);
  for (int i = 0; i < row; i++) {
    printf("[");
    for (int j = 0; j < col; j++) {
      printf(" %d ", mat[i][j]);
    }
    printf("]\n");
  }
}

void displaySparseMatrix() {

}

int main() {

}
