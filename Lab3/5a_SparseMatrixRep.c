#include <stdio.h>
#define MAX 101

typedef struct {
    int col;
    int row;
    int val;
} Matrix;

Matrix a[MAX];

void convert(int row, int col, int mat[row][col], int terms) {
    a[0].row = row;
    a[0].col = col;
    a[0].val = terms;
    
    int k = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        if (mat[i][j] != 0) {
            a[k].row = i;
            a[k].col = j;
            a[k].val = mat[i][j];
            k++;
        }
        }
    }
}

void displayMatrix(int row, int col, int mat[row][col]) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        printf("[");
        for (int j = 0; j < col; j++) {
            printf(" %d ", mat[i][j]);
        }
        printf("]\n");
    }
}

void displaySparseMatrix(Matrix *m) {
    int terms = m[0].val;
    printf("Row\tCol\tVal\n");
    for(int i = 0; i < terms + 1; i++) {
        printf("%d\t%d\t%d\n", m[i].row, m[i].col, m[i].val);
    }
}

int main() {
    int row, col, terms = 0;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    
    if (row <= 0 || col <= 0) {
        printf("ERROR: Invalid Matrix Dimensions\n");
        return 1;
    }

    int mat[row][col];
    for (int i = 0; i < row; i++) {
        printf("Enter elements in row %d:\n", i+1);
        for (int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] != 0) {
                terms++;
            }
        }
    }
    displayMatrix(row, col, mat);

    convert(row, col, mat, terms);
    printf("Sparse Matrix:\n");
    displaySparseMatrix(a);
    return 0;
}
