/*Two stack in a single array*/

#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// Push in Stack 1
void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow\n");
        return;
    }
    arr[++top1] = x;
}

// Push in Stack 2
void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow\n");
        return;
    }
    arr[--top2] = x;
}

// Pop from Stack 1
void pop1() {
    if (top1 == -1) {
        printf("Stack1 Underflow\n");
        return;
    }
    printf("Popped from Stack1: %d\n", arr[top1--]);
}

// Pop from Stack 2
void pop2() {
    if (top2 == MAX) {
        printf("Stack2 Underflow\n");
        return;
    }
    printf("Popped from Stack2: %d\n", arr[top2++]);
}

// Display both stacks
void display() {
    printf("\nStack1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nStack2: ");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- TWO STACK MENU ---\n");
        printf("1. Push Stack1\n");
        printf("2. Push Stack2\n");
        printf("3. Pop Stack1\n");
        printf("4. Pop Stack2\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}