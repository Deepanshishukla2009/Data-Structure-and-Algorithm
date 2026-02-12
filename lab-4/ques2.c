#include <stdio.h>

int main() {
    int rA, cA, rB, cB;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rA, &cA);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rB, &cB);
    if (cA != rB) {
        printf("\nMatrix multiplication not possible! (Columns of A must equal rows of B)\n");
        return 0;
    }
    int A[rA][cA], B[rB][cB], Product[rA][cB];
    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < rB; i++) {
        for (int j = 0; j < cB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            Product[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                Product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nResultant Matrix after Multiplication:\n");
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            printf("%d ", Product[i][j]);
        }
        printf("\n");
    }

    return 0;
}