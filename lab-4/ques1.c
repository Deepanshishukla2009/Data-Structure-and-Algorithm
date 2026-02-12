#include <stdio.h>

int main() {
    int rA, cA, rB, cB;

   
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &rA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &cA);

   
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &rB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &cB);

   
    if (rA != rB || cA != cB) {
        printf("\nMatrix addition and subtraction not possible!");
        printf("\nBoth matrices must have the same number of rows and columns.\n");
        return 0; 
    }

  
    int A[rA][cA], B[rB][cB], Sum[rA][cA], Diff[rA][cA];

  
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
        for (int j = 0; j < cA; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
            Diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nResultant Matrix after Addition:\n");
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant Matrix after Subtraction:\n");
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            printf("%d ", Diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}