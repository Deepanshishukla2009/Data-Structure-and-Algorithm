#include <stdio.h>
#include <time.h>
int main() {
    int n, pos, x;
    int arr[100];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements (n): ");
    scanf("%d", &n);

     if (n > 100) {
        printf("Array size exceeds maximum capacity (100).\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to insert (x): ");
    scanf("%d", &x);

    printf("Enter position (1-based index): ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Must be between 1 and %d.\n", n + 1);
        return 1;
    }

    if (n == 100) {
        printf("Array overflow! Cannot insert new element.\n");
        return 1;
    }
 start = clock();
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++; 
     end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n Time = %f seconds\n", time_taken);

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}