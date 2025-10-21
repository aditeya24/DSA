#include <stdio.h>
#define MAX 101

typedef struct {
    int col;
    int row;
    int val;
} Matrix;

Matrix a[MAX], b[MAX], c[MAX];

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

void transpose() {
    int t = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = t;

    if(t > 0) {
        int k = 1;
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= t; j++) {
                if (a[j].col == i) {
                    b[k].row = a[j].col;
                    b[k].col = a[j].row;
                    b[k].val = a[j].val;
                    k++;
                }
            }
        }
    }
}

void fastTranspose() {
    int t = a[0].val;
    c[0].row = a[0].col;
    c[0].col = a[0].row;
    c[0].val = t;
    
    int row_terms[a[0].col], starting_pos[a[0].col];

    if (t > 0) {
        for (int i = 0; i < a[0].col; i++) {
            row_terms[i] = 0;
        }
        for (int i = 0; i <= t; i++) {
            row_terms[a[i].col]++;
        }
        starting_pos[0] = 1;
        for (int i = 1; i <= a[0].col; i++) {
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }
        for (int i = 1; i <= t; i++) {
            int j = starting_pos[a[i].col]++;
            c[j].row = a[i].col;
            c[j].col = a[i].row;
            c[j].val = a[i].val;
        }
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

    transpose();
    printf("Transpose:\n");
    displaySparseMatrix(b);

    fastTranspose();
    printf("Fast Transpose:\n");
    displaySparseMatrix(c);
    return 0;
}
