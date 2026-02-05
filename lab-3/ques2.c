#include <stdio.h>
#include <time.h>
int main() {
    int arr[100],n, i,x;
    clock_t start, end;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);
 if (n > 100) {
        printf("Array size exceeds maximum capacity (100).\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert at beginning: ");
    scanf("%d", &x);

  if (n == 100) {
        printf("Array overflow! Cannot insert new element.\n");
        return 1;
    }
 start = clock();
    for(i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
 end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n Time = %f seconds\n", time_taken);

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}