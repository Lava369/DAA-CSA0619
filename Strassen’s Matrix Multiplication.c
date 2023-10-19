#include <stdio.h>
void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassenMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize];
    int P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    addMatrix(newSize, A11, A22, C11);
    addMatrix(newSize, B11, B22, C12);
    strassenMultiply(newSize, C11, C12, P1);

    addMatrix(newSize, A21, A22, C11);
    strassenMultiply(newSize, C11, B11, P2);

    subtractMatrix(newSize, B12, B22, C11);
    strassenMultiply(newSize, A11, C11, P3);

    subtractMatrix(newSize, B21, B11, C11);
    strassenMultiply(newSize, A22, C11, P4);

    addMatrix(newSize, A11, A12, C11);
    strassenMultiply(newSize, C11, B22, P5);

    subtractMatrix(newSize, A21, A11, C11);
    addMatrix(newSize, B11, B12, C12);
    strassenMultiply(newSize, C11, C12, P6);
    subtractMatrix(newSize, A12, A22, C11);
    addMatrix(newSize, B21, B22, C12);
    strassenMultiply(newSize, C11, C12, P7);
    addMatrix(newSize, P1, P4, C11);
    subtractMatrix(newSize, P7, P5, C12);
    addMatrix(newSize, P3, P5, C21);
    addMatrix(newSize, P2, P6, C22);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}
void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n; 
    printf("Enter the size of matrices (n x n): ");
    scanf("%d", &n);
    if ((n & (n - 1)) != 0) {
        printf("Matrix size must be a power of 2 for this implementation.\n");
        return 1;
    }

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassenMultiply(n, A, B, C);
    printf("Matrix A:\n");
    printMatrix(n, A);
    printf("Matrix B:\n");
    printMatrix(n, B);
    printf("Resultant Matrix C:\n");
    printMatrix(n, C);
    return 0;
}

