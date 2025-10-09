#include <stdio.h>
#define MAX 101

typedef struct {
    int col;
    int row;
    int val;
} Matrix;

Matrix a[MAX], b[MAX], c[MAX];

void convert(int row, int col, int mat[row][col], int terms, Matrix *m) {
    m[0].row = row;
    m[0].col = col;
    m[0].val = terms;
    
    int k = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                m[k].row = i;
                m[k].col = j;
                m[k].val = mat[i][j];
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

void sum(Matrix *a, Matrix *b, Matrix *c) {
    int i = 1, j = 1, k = 1;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row) {
            c[k++] = a[i++];
        } else if (a[i].row > b[j].row) {
            c[k++] = b[j++];
        } else {
            if (a[i].col < b[j].col) {
                c[k++] = a[i++];
            } else if (a[i].col > b[j].col) {
                c[k++] = b[j++];
            } else {
                int sum = a[i].val + b[j].val;
                if (sum != 0) {
                    c[k].row = a[i].row;
                    c[k].col = a[i].col;
                    c[k].val = sum;
                    k++;
                }
                i++;
                j++;
            }
        }
    }

    while (i <= a[0].val) {
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].val = a[i].val;
        i++;
        k++;
    }
    while (j <= b[0].val) {
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].val = b[j].val;
        j++;
        k++;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;
    c[0].val = k - 1;
}

int main() {
    int row, col, terms_A = 0, terms_B = 0;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    
    if (row <= 0 || col <= 0) {
        printf("ERROR: Invalid Matrix Dimensions\n");
        return 1;
    }

    int matA[row][col];
    printf("Input for Matrix A:\n");
    for (int i = 0; i < row; i++) {
        printf("Enter elements in row %d:\n", i+1);
        for (int j = 0; j < col; j++) {
            scanf("%d", &matA[i][j]);
            if (matA[i][j] != 0) {
                terms_A++;
            }
        }
    }
    displayMatrix(row, col, matA);
    
    int matB[row][col];
    printf("Input for Matrix B:\n");
    for (int i = 0; i < row; i++) {
        printf("Enter elements in row %d:\n", i+1);
        for (int j = 0; j < col; j++) {
            scanf("%d", &matB[i][j]);
            if (matB[i][j] != 0) {
                terms_B++;
            }
        }
    }
    displayMatrix(row, col, matB);

    convert(row, col, matA, terms_A, a);
    printf("Sparse Matrix A:\n");
    displaySparseMatrix(a);

    convert(row, col, matB, terms_B, b);
    printf("Sparse Matrix B:\n");
    displaySparseMatrix(b);
    
    sum(a, b, c);
    printf("Sum:\n");
    displaySparseMatrix(c);

    return 0;
}
