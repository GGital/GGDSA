#include<stdio.h>

int main() {
    int matrix[3][3] = {0};

    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i][j] = i + j;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d " , matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Matrix Addition
    int matrix2[3][3] = {0};
    int matrix3[3][3] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix2[i][j] = i + j;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix3[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d " , matrix3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Matrix Multiplication
    // k is col of A or row of B
    int matrix4[3][3] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++)
            matrix4[i][j] += matrix[i][k] * matrix2[k][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d " , matrix4[i][j]);
        }
        printf("\n");
    }
    return 0;
}
