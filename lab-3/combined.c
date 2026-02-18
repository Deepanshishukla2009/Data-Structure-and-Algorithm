//insertion on array(beginning,last,given index)
#include <stdio.h>
#include <time.h>
int main() {
    int arr[100], n, i, x, pos, choice;
    clock_t start, end;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n > 100) {
        printf("Array size exceeds maximum capacity (100).\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\nChoose insertion type:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at specific position\n");
        printf("3. Insert at end\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

        if (n == 100) {
            printf("Array overflow! Cannot insert new element.\n");
            continue;
        }

        printf("Enter element to insert: ");
        scanf("%d", &x);

        start = clock();

        if (choice == 1) {
            // Insert at beginning
            for (i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = x;
            n++;
        } else if (choice == 2) {
            // Insert at given position
            printf("Enter position (1-based index): ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n + 1) {
                printf("Invalid position! Must be between 1 and %d.\n", n + 1);
                continue;
            }

            for (i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = x;
            n++;
        } else if (choice == 3) {
            // Insert at end
            arr[n] = x;
            n++;
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nTime taken for insertion = %f seconds\n", time_taken);

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}