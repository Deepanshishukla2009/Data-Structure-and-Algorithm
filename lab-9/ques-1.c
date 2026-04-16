/* Binary Tree using array*/

#include <stdio.h>

#define SIZE 10

int tree[SIZE];

// Initialize
void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

// Insert (level order)
void insert(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == -1) {
            tree[i] = value;
            return;
        }
    }
    printf("Tree is full\n");
}

// Display (simple)
void display() {
    printf("Binary Tree (Array form):\n");
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    return 0;
}