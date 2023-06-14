//Khushi Desai

//CODE FOR STANDARD O(n^3) MATRIX MULTIPLICATION ALGORITHM:
#include <stdio.h>
//function to initially create null matrix and update the values after multiplying and adding the rows and cols 
void matrix_multiply(int n, int a[][n], int b[][n], int c[][n]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n];
    int i, j;

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);  //taking matrix input from user
        }
    }

    matrix_multiply(n, a, b, c);

    printf("Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n"); // printing the matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
