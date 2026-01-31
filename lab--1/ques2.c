#include <stdio.h>;
#include <time.h>

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start = clock();

    // Outer loop runs n times
    for (i = 1; i <= n; i++) {
        int temp = 1;
        // Inner loop runs log(n) times
        while (temp <= n) {
            temp = temp * 2;   // doubling until > n
        }
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time = %f seconds\n", time_taken);

    return 0;
}