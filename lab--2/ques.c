#include <stdio.h>
#include <stdlib.h>   
#include <time.h>     

int main() {
    int arr[100000], tempArr[100000];
    int n, i, j, key;
    clock_t start, end;
    double time_taken;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    srand(time(0));
    printf("Randomly generated array:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  
        printf("%d ", arr[i]);
    }

    // ---------------- Best Case ----------------
    // Sort array ascending first (best case input for insertion sort)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    start = clock();
    // Insertion Sort on already sorted array (Best Case)
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nBest Case Time = %f seconds", time_taken);

    // ---------------- Worst Case ----------------
    // Sort array descending first (worst case input for insertion sort)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    start = clock();
    // Insertion Sort on reverse sorted array (Worst Case)
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
     
    printf("\nWorst Case Time = %f seconds\n", time_taken);

    return 0;
}