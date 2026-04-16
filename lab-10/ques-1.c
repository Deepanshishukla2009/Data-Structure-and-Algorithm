/*BST using array*/

#include <stdio.h>
#define SIZE 100

int tree[SIZE];  

void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

void insert(int value, int index) {
    if (index >= SIZE) {
        printf("Tree is full\n");
        return;
    }

    if (tree[index] == -1) {
        tree[index] = value;
        return;
    }

    if (value < tree[index]) {
        insert(value, 2 * index + 1);   // Left child
    } else {
        insert(value, 2 * index + 2);   // Right child
    }
}

void inorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void display() {
    printf("\nArray Representation:\n");
    for (int i = 0; i < 15; i++) {
        if (tree[i] == -1)
            printf("NULL ");
        else
            printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    init();

    insert(50, 0);
    insert(30, 0);
    insert(70, 0);
    insert(20, 0);
    insert(40, 0);
    insert(60, 0);
    insert(80, 0);

    printf("Inorder Traversal:\n");
    inorder(0);

    display();

    return 0;
}