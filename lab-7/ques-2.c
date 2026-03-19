/*Stack implementation using linkedlist*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack\n", temp->data);

    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void display() {
    struct Node* temp = top;

    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}